## Core

Contains the domain entities and the use cases that work with them.  
This also contains specific ports to allow communication between core and adapters.  
For driving adapters, ports are use case interfaces implemented in the core and called by the adapter.  
For a driven adapter, ports are interfaces implemented by the adapter and called by the core.  