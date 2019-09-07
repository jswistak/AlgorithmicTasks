CXXFLAGS=-std=c++11 -Wall -Wextra -g
LDLIBS=-lcurl

bot: bot.o game.o
	$(CXX) bot.o game.o $(LDLIBS) -o bot

bot.o: bot.cpp game.h
game.o: game.cpp game.h

clean:
	rm -f bot *.o
