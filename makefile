TARGET = bubble
CC = g++
SOURCES = laba1.cpp
OBJECTS = $(SOURCES:.cpp=.o)
ARRAY = 20 140 4
check_deps:
	@command -v $(CC) >/dev/null 2>&1 || { echo >&2 "Компилятор G++ не установлен. Установите его с помощью: sudo apt install g++"; exit 1; }
	@command -v make >/dev/null 2>&1 || { echo >&2 "make не установлен. Установите его с помощью: sudo apt install make"; exit 1; }
all: check_deps $(TARGET)
$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)
%.o: %.cpp
	$(CC) -c $< -o $@
run: $(TARGET)
	./$(TARGET) "$(ARRAY)"
clean:
	rm -f $(TARGET) $(OBJECTS)