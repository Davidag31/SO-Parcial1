# Compilador y flags
CXX = g++
CXXFLAGS = -std=c++11 -Iinclude -Wall -Wextra

# Directorios
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

# Archivos fuente y de cabecera
SRCS = $(wildcard $(SRC_DIR)/*.cpp) main.cpp
OBJS = $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

# Archivo ejecutable
TARGET = $(BUILD_DIR)/chat

# Regla por defecto
all: $(TARGET)

# Regla para crear el directorio de compilación
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)/$(SRC_DIR)

# Regla para compilar el ejecutable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regla para compilar los archivos objeto
$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpiar archivos compilados
clean:
	rm -rf $(BUILD_DIR)

# Ejecutar el servidor con puerto dinámico
run-servidor: $(TARGET)
	@read -p "Ingrese el puerto para el servidor: " port; \
	./$(TARGET) servidor $$port

# Ejecutar el cliente con puerto y dirección IP dinámicos
run-cliente: $(TARGET)
	@read -p "Ingrese la dirección IP del servidor: " ip; \
	read -p "Ingrese el puerto del servidor: " port; \
	./$(TARGET) cliente $$ip $$port

# Regla para forzar la recompilación
rebuild: clean all

# Declarar reglas como phony
.PHONY: all clean run-servidor run-cliente rebuild
