## Source Code Coverage Report  
```
Reading tracefile /home/runner/work/toy-robot/toy-robot/test/../test/coverage.info
Summary coverage rate:
  lines......: 94.1% (289 of 307 lines)
  functions..: 88.1% (96 of 109 functions)
  branches...: 52.3% (228 of 436 branches)

                                               |Lines      |Functions|Branches  
Filename                                       |Rate    Num|Rate  Num|Rate   Num
================================================================================
[/home/runner/work/toy-robot/toy-robot/src/GameServer/Adapters/In/PlayerControls/]
BaseController.h                               | 100%     1|50.0%   2|    -    0
GetObjectPositionController.cc                 | 100%     9| 100%   1|55.0%   40
GetObjectPositionController.h                  | 100%     2| 100%   1|    -    0
MoveObjectController.cc                        | 100%     6| 100%   1|60.0%   10
MoveObjectController.h                         | 100%     2| 100%   1|    -    0
PlaceObjectController.cc                       |76.5%    17| 100%   3|42.9%   42
PlaceObjectController.h                        | 100%     2| 100%   1|    -    0
RequestRouter.cc                               |57.1%    14| 100%   2|26.7%   30
RotateObjectController.cc                      | 100%     6| 100%   1|60.0%   10
RotateObjectController.h                       | 100%     2| 100%   1|    -    0

[/home/runner/work/toy-robot/toy-robot/src/GameServer/Adapters/Out/Persistence/]
MapPersistenceAdapter.cc                       | 100%     8| 100%   2|58.3%   12
ObjectPersistenceAdapter.cc                    | 100%     8| 100%   2|57.1%   14

[/home/runner/work/toy-robot/toy-robot/src/GameServer/Core/]
Domain/BaseObject.h                            | 100%     9|90.0%  10|    -    0
Domain/Exception/BaseException.h               | 100%     1| 100%   1|    -    0
Domain/Exception/InvalidActionException.h      | 100%     1| 100%   1|    -    0
Domain/Exception/InvalidCoordinatesException.h | 100%     1| 100%   1|    -    0
Domain/Exception/InvalidObjectIdException.h    | 100%     1| 100%   1|    -    0
Domain/Exception/InvalidOrientationException.h | 0.0%     1| 0.0%   1|    -    0
Domain/Exception/InvalidParametersException.h  | 0.0%     1| 0.0%   1|    -    0
Domain/Exception/InvalidStateException.h       | 100%     1| 100%   1|    -    0
Domain/Map.cc                                  |93.1%    29| 100%   8|38.5%   26
Domain/Map.h                                   | 100%     5| 100%   6|    -    0
Domain/Movable.h                               | 100%     1|50.0%   2|    -    0
Domain/Placeable.h                             | 100%     1|50.0%   2|    -    0
Domain/Robot.cc                                | 100%    14| 100%   4|    -    0
Domain/Robot.h                                 | 100%     1| 100%   1|    -    0
Domain/Rotatable.h                             | 100%     1|50.0%   2|    -    0
Domain/Value/Coordinates.h                     | 100%     6| 100%   4|50.0%    8
Domain/Value/Orientation.cc                    | 100%    32| 100%   6|62.5%   48
Domain/Value/Orientation.h                     |91.7%    12| 100%   5|56.2%   16
Domain/Value/Rotation.cc                       | 100%     6| 100%   2|50.0%   16
Domain/Value/Rotation.h                        |85.7%     7| 100%   2|40.0%   10
Ports/In/GetObjectPositionUseCase.h            | 100%     1|50.0%   2|    -    0
Ports/In/MoveObjectUseCase.h                   | 100%     1|50.0%   2|    -    0
Ports/In/PlaceObjectUseCase.h                  | 100%     1|50.0%   2|    -    0
Ports/In/RotateObjectUseCase.h                 | 100%     1|50.0%   2|    -    0
Ports/In/data/MoveObjectCommand.h              | 100%     1| 100%   1|    -    0
Ports/In/data/PlaceObjectCommand.h             | 100%     2| 100%   1|    -    0
Ports/In/data/QueryResponse.h                  | 100%     4| 100%   2|50.0%    2
Ports/In/data/RotateObjectCommand.h            | 100%     2| 100%   1|    -    0
Ports/Out/MapRepository.h                      | 100%     1|50.0%   2|    -    0
Ports/Out/ObjectRepository.h                   | 100%     1|50.0%   2|    -    0
Services/GetObjectPositionService.cc           | 100%    12| 100%   1|52.4%   42
Services/GetObjectPositionService.h            | 100%     2| 100%   1|    -    0
Services/MoveObjectService.cc                  |97.1%    34| 100%   4|66.7%   66
Services/MoveObjectService.h                   | 100%     3| 100%   1|    -    0
Services/PlaceObjectService.cc                 |93.3%    15| 100%   2|39.3%   28
Services/PlaceObjectService.h                  | 100%     3| 100%   1|    -    0
Services/RotateObjectService.cc                | 100%    13| 100%   2|62.5%   16
Services/RotateObjectService.h                 | 100%     2| 100%   1|    -    0
================================================================================
                                         Total:|94.1%   307|88.1% 109|52.3%  436
```
