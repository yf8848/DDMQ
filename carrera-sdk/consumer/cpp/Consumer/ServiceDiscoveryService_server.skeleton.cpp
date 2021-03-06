// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "ServiceDiscoveryService.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace  ::CarreraServiceDiscovery;

class ServiceDiscoveryServiceHandler : virtual public ServiceDiscoveryServiceIf {
 public:
  ServiceDiscoveryServiceHandler() {
    // Your initialization goes here
  }

  void discoverProducerService(ServiceMeta& _return, const std::string& topic, const ClientMeta& meta) {
    // Your implementation goes here
    printf("discoverProducerService\n");
  }

  void discoverConsumerService(ServiceMeta& _return, const std::string& group, const ClientMeta& meta) {
    // Your implementation goes here
    printf("discoverConsumerService\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  shared_ptr<ServiceDiscoveryServiceHandler> handler(new ServiceDiscoveryServiceHandler());
  shared_ptr<TProcessor> processor(new ServiceDiscoveryServiceProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

