#!/usr/bin/sh

mkdir -p build

tcc -g \
-L./src/thirdparty/raylib/src \
-I./src/thirdparty/raylib/src \
-I./src/thirdparty/raygui/src \
-I./src \
src/rsrc/font_SpaceMono.c \
src/citizen.c \
src/drawing.c \
src/entities/george.c \
src/entities/gatherer.c \
src/fix_string_raylib.c \
src/impl.c \
src/ingame.c \
src/main.c \
src/menu.c \
src/pathfinding.c \
src/settlement.c \
src/ui.c \
src/world.c \
-o ./build/afterthought \
-lraylib -lm 