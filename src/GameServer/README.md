## Game Server

Contains implementation of the Game Server's components.  

The ccontroller calls an incoming port, which is implemented by a service.  
The service calls an outgoing port, which is implemented by an adapter.  
Within the service, an entity is manipulated to perform a use case.
