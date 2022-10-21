

# c语言

## define

`#` 用来将后面内容转成字符串

```c
// #src等同于"src"
#define strcpy__(dst, src)  strcpy(dst, #src) 
```



`##`用来连接前后内容

```c
// new_##name等同于new_name
#define newname(name)    new_##name 
```



