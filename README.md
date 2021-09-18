# cmake 学习示例


# find_package
根据优先级顺序，在指定路径查找Findxxx.cmake 和 xxxConfig.cmake 只要找到一个就找到该库
|常用变量            |常用指令                   |含义  |
|---------          |-------                    |-----        |
|\<NAME>_FOUND       |if(\<NAME>_FOUND)           | 找到库标志   |
|\<NAME>_INCLUDE_DIR |find_path(\<NAME>_INCLUDES) | 头文件路径   |  
|\<NAME>_INCLUDES    |                           |          |   
|\<NAME>_LIBRARY     |find_library(\<NAME>_LIBS)  |  库文件路径  |  
|\<NAME>_LIBS        |                           |             |

* 示例
```
find_path(u_common_INCLUDE_DIR
NAMES common_api.h
PATHS src/u_common/src)

find_library(u_common_LIBRARY
NAMES u_common
PATHS ${PROJECT_BINARY_DIR})
```