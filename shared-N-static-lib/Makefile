LIB_NAME := hello

CUR_DIR := .
BIN_DIR := $(CUR_DIR)/bin
INC_DIR := $(CUR_DIR)/inc
SRC_DIR := $(CUR_DIR)/src
OBJ_DIR := $(CUR_DIR)/obj
LIB_DIR := $(CUR_DIR)/lib
LIB_STATIC_DIR := $(LIB_DIR)/static
LIB_SHARED_DIR := $(LIB_DIR)/shared

sharedlib: 
# create_obj:
	gcc -c -fPIC $(CUR_DIR)/main.c -o $(OBJ_DIR)/main.o -I $(INC_DIR)
	gcc -c -fPIC $(SRC_DIR)/hello.c -o $(OBJ_DIR)/hello.o -I $(INC_DIR)
# create_sharedlib:
	gcc -shared $(OBJ_DIR)/hello.o -o $(LIB_SHARED_DIR)/lib$(LIB_NAME).so
# install:
	cp -f $(LIB_SHARED_DIR)/lib$(LIB_NAME).so /usr/lib
# linking:
	gcc  $(OBJ_DIR)/main.o -L$(LIB_SHARED_DIR) -lhello -o $(BIN_DIR)/shared-lib

staticlib:
# create_obj:
	gcc -c $(CUR_DIR)/main.c -o $(OBJ_DIR)/main.o -I $(INC_DIR)
	gcc -c $(SRC_DIR)/hello.c -o $(OBJ_DIR)/hello.o -I $(INC_DIR)
#create_staticlib:
	ar rcs $(LIB_STATIC_DIR)/lib$(LIB_NAME).a $(OBJ_DIR)/hello.o
# linking:
	gcc $(OBJ_DIR)/main.o  -L$(LIB_STATIC_DIR) -lhello -o $(BIN_DIR)/static-lib

clean:
	rm -f $(OBJ_DIR)/*.o
	rm -f $(BIN_DIR)/*
	rm -f $(LIB_STATIC_DIR)/*
	rm -f $(LIB_SHARED_DIR)/*