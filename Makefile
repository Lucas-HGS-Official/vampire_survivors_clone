TARGET = bin/game
SRC = $(wildcard code/src/*.cpp)
OBJ = $(patsubst code/src/%.cpp, code/obj/%.o, $(SRC))
WEB_RAYLIB = code/libs/static_libs/web

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
	emcc -o $(TARGET).html code/src/main.cpp -Os -Wall ./$(WEB_RAYLIB)/libraylib.a -Icode/include -Icode/libs/include -I/home/lhgs/raylib/src -L$(WEB_RAYLIB) -s USE_GLFW=3 -s ASYNCIFY -s TOTAL_MEMORY=67108864 -s STACK_SIZE=20MB -s ASSERTIONS=1 -s EXPORTED_RUNTIME_METHODS=ccall --profiling -DPLATFORM_WEB
# --preload-file resources

###################################

###################################
# Run Game
###################################
run:
	./$(TARGET)

web_run:
	emrun $(TARGET).html
###################################
