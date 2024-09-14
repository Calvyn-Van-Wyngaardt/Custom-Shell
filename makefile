SRC_DIR = src
OBJECTS_DIR = obj
BIN_DIR = bin

make: $(SRC_DIR)
	g++ $(SRC_DIR)/*.cpp -o $(BIN_DIR)/main

run:
	./$(BIN_DIR)/main

clean:
	rm $(BIN_DIR)/*