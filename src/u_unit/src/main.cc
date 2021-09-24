#include <iostream>

#include "NumPublisher.h"
#include "NumSubscriber.h"

#define LOG_INFO(s) std::cout << s << std::endl

void usage() { LOG_INFO("node sub/pub"); }

int node_subscriber() {
  NumSubscriber mysub;
  if (mysub.init()) {
    mysub.run();
  }
  return 0;
}

int node_publisher() {
  NumPublisher mypub;
  if (mypub.init()) {
    mypub.run();
  }
  return 0;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    usage();
    return 1;
  }
  LOG_INFO("node cmd=" << argv[1]);
  if (std::strcmp(argv[1], "sub") == 0) {
      node_subscriber();
  } else if (std::strcmp(argv[1], "pub") == 0) {
      node_publisher();
  } else {
    usage();
    return 1;
  }
  return 0;
}