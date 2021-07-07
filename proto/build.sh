protoc --cpp_out=./ testBuffer.proto
cp testBuffer.pb.h ../src/
cp testBuffer.pb.h ../stressTest/