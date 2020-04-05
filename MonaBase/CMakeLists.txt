cmake_minimum_required(VERSION 3.5)
set(PROJECT_NAME MonaBase)
project(${PROJECT_NAME})

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)

# Collecting a list of sources.
#<???> file(GLOB SOURCE_FILES sources/*.h sources/*.cpp)
file(GLOB SOURCE_FILES
        sources/Application.cpp
        sources/Crypto.cpp
        sources/File.cpp
        sources/IPAddress.cpp
        sources/Net.cpp
        sources/PoolBuffers.cpp
        sources/Signal.cpp
        sources/Startable.cpp
        sources/TCPClient.cpp
        sources/UDPSocket.cpp
        sources/AttemptCounter.cpp
        sources/Date.cpp
        sources/FileSystem.cpp
        sources/Logger.cpp
        sources/Option.cpp
        sources/PoolThread.cpp
        sources/SocketAddress.cpp
        sources/String.cpp
        sources/TCPServer.cpp
        sources/Util.cpp
        sources/BinaryReader.cpp
        sources/DiffieHellman.cpp
        sources/FileWatcher.cpp
        sources/Logs.cpp
        sources/Options.cpp
        sources/Process.cpp
        sources/Socket.cpp
        sources/SubstreamMap.cpp
        sources/TerminateSignal.cpp
        sources/BinaryWriter.cpp
        sources/DNS.cpp
        sources/HelpFormatter.cpp
        sources/MapParameters.cpp
        sources/Parameters.cpp
        sources/QualityOfService.cpp
        sources/SocketManager.cpp
        sources/Task.cpp
        sources/Timezone.cpp
        sources/Buffer.cpp
        sources/Exceptions.cpp
        sources/HostEntry.cpp
        sources/Mona.cpp
        sources/PersistentData.cpp
        sources/ServerApplication.cpp
        sources/SocketSender.cpp
        sources/TaskHandler.cpp
        sources/Trigger.cpp
        sources/XMLParser.cpp
        sources/MonaFilter.cpp
        )
#
include_directories("${CMAKE_SOURCE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}/include")

add_library(${PROJECT_NAME} SHARED ${INCLUDE_FILES} ${SOURCE_FILES})
