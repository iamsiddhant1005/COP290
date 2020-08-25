all:
	kcc -c Customer.c -o Customer.o
	kcc -c Teller.c -o Teller.o
	kcc -c Event.c -o Event.o
	kcc -c eventQueue.c -o eventQueue.o
	kcc -c tellerQueue.c -o tellerQueue.o
	ar cr libCustomer.a Customer.o
	ar cr libTeller.a Teller.o
	ar cr libEvent.a Event.o
	ar cr libtellerQueue.a tellerQueue.o
	ar cr libeventQueue.a eventQueue.o
	kcc ass6.c -L. -I. -lCustomer -lTeller -lEvent -ltellerQueue -leventQueue -lm -o a






# Usage:
# make        # compile all binary
# make clean  # remove ALL binaries and objects

.PHONY = all clean

CC = kcc
# compiler to use

OBJ_DIR = obj
EXE_DIR = bin
SRC_DIR = src
UTIL_DIR = util
LIB_DIR = lib


LINKERFLAG = -lm





all: $(OBJ_DIR)/qSim
	
$(LIB_DIR)/libCustomer.a: $(UTIL_DIR)/Customer.c
	@kcc -I./include/ -c $(UTIL_DIR)/Customer.c -o $(OBJ_DIR)/Customer.o
	@echo "here"
	@ar cr $(LIB_DIR)/libCustomer.a $(OBJ_DIR)/Customer.o
	@echo "Customer Library Created"
$(LIB_DIR)/libTeller.a: $(UTIL_DIR)/Teller.c
	@kcc -I./include/ -c $(UTIL_DIR)/Teller.c -o $(OBJ_DIR)/Teller.o
	@echo "here"
	@ar cr $(LIB_DIR)/libTeller.a $(OBJ_DIR)/Teller.o
	@echo " Teller Library Created"
$(LIB_DIR)/libEvent.a: $(UTIL_DIR)/Event.c
	@kcc -I./include/ -c $(UTIL_DIR)/Event.c -o $(OBJ_DIR)/Event.o
	@echo "here"
	@ar cr $(LIB_DIR)/libEvent.a $(OBJ_DIR)/Event.o
	@echo "Event Library Created"		
$(LIB_DIR)/libeventQueue.a: $(UTIL_DIR)/eventQueue.c
	@kcc -I./include/ -c $(UTIL_DIR)/eventQueue.c -o $(OBJ_DIR)/eventQueue.o
	@echo "here"
	@ar cr $(LIB_DIR)/libeventQueue.a $(OBJ_DIR)/eventQueue.o
	@echo "Event Queue Library Created"
$(LIB_DIR)/libtellerQueue.a: $(UTIL_DIR)/tellerQueue.c
	@kcc -I./include/ -c $(UTIL_DIR)/tellerQueue.c -o $(OBJ_DIR)/tellerQueue.o
	@echo "here"
	@ar cr $(LIB_DIR)/libtellerQueue.a $(OBJ_DIR)/tellerQueue.o
	@echo "Teller Queue Library Created"	


$(OBJ_DIR)/qSim: $(SRC_DIR)/main.c $(LIB_DIR)/libCustomer.a $(LIB_DIR)/libTeller.a $(LIB_DIR)/libEvent.a $(LIB_DIR)/libeventQueue.a $(LIB_DIR)/libtellerQueue.a
	@echo "Creating object.."
	$(CC) -lm -L./lib/-lCustomer -L./lib/-lTeller -L./lib/-lEvent -L./lib/-ltellerQueue -L./lib/-leventQueue -I./include/ -c $(SRC_DIR)/main.c -o $(OBJ_DIR)/qSim

run:
	./obj/qSim 100 4 60 2.3
clean:
	@echo "Cleaning up..."
	rm $(OBJ_DIR)/qSim 
	