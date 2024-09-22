# Nome do executável
TARGET = avl_tree

# Compilador
CC = g++

# Flags do compilador
CFLAGS = -Wall -g

# Arquivos fonte
SRCS = main.cpp avl_tree.cpp

# Arquivos objeto
OBJS = $(SRCS:.cpp=.o)

# Regra padrão para construir o projeto
all: $(TARGET)

# Regra para criar o executável
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Regra para compilar os arquivos .cpp em .o
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Limpa os arquivos objeto e o executável
clean:
	rm -f $(OBJS) $(TARGET)

# Executar o programa
run: $(TARGET)
	./$(TARGET)
