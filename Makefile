TARGET = bin/game
WEB_TARGET = bin/game.html
SRC = $(wildcard code/src/*.cpp)
OBJ = $(patsubst code/src/%.cpp, code/obj/%.o, $(SRC))
WEB_LIBS = code/libs/static_libs/web

LIB_SRC = $(wildcard code/libs/src/*.c)
LIB_OBJ = $(patsubst code/libs/src/%.c, code/libs/obj/%.o, $(LIB_SRC))

###################################
# Build Everything
###################################
default: from_scratch

from_scratch: clean build web_build
###################################

###################################
# Build Game
###################################
build: $(TARGET)

$(TARGET): $(OBJ)
	g++ -o $@ $? -std=c++20 -Wall -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

code/obj/%.o : code/src/%.cpp
	g++ -c $< -o $@ -Icode/include -Icode/libs/include

clean:
	rm -f code/obj/*.o
	rm -f $(TARGET)*
###################################

###################################
# Build Web
###################################
update_emcc:
	~/emsdk/emsdk install latest

activate_emcc:
	~/emsdk/emsdk activate latest

web_build:
	emcc -o $(WEB_TARGET) $(SRC) -Os -Wall ./$(WEB_LIBS)/libraylib.a -Icode/include -Icode/libs/include -I/home/lhgs/raylib/src -L$(WEB_LIBS) -s USE_GLFW=3 -s ASYNCIFY -s TOTAL_MEMORY=67108864 -s STACK_SIZE=20MB -s ASSERTIONS=1 -s EXPORTED_RUNTIME_METHODS=ccall --profiling --preload-file resources -DPLATFORM_WEB
###################################

###################################
# Run Game
###################################
run:
	./$(TARGET)

web_run:
	emrun $(TARGET).html
###################################
