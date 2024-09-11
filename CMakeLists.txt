cmake_minimum_required(VERSION 3.28)
project(pishti)

set(CMAKE_CXX_STANDARD 11)

add_executable(pishti src/main.cpp
        src/Card.cpp
        include/Card.h
        src/CardList.cpp
        include/CardList.h
        src/Deck.cpp
        include/Deck.h
        src/HumanPlayer.cpp
        include/HumanPlayer.h
        include/Player.h
        src/Pishti.cpp
        include/Pishti.h
        src/ComputerPlayer.cpp
        include/ComputerPlayer.h
        include/CardFactory.h
        src/CardFactory.cpp
        include/PishtiEvent.h
        src/Manager.cpp
        include/Manager.h
        include/PishtiObserver.h
        src/Player.cpp
        include/DisplayStrategy.h
        include/ConsoleDisplay.h
        src/ConsoleDisplay.cpp
)
