# Awesome3dX
Graphics Programming with DirectX

## Note

`CreateWindowEx` is a macro, which expands to either `CreateWindowExA` or `CreateWindowExW` based on whether UNICODE has been defined. Many WinAPI functions work this way: they have a macro which switches between the appropriate functions based on UNICODE, then have the **A** and **W** versions.

Now, the difference between the **A** and **W** versions is simple.

The **A** version handles text based on Windows code pages, while the **W** version handles Unicode text.

If we use **A** version and set window title, we get freaking Chinese characters in the title area. 

![image](https://user-images.githubusercontent.com/16564582/184525870-f88c7b7f-22e8-4196-8e2b-7dfb2196f172.png)

But if we switch to the **W** version, we get a nice result.

![image](https://user-images.githubusercontent.com/16564582/184525955-22b00ac8-8913-40d9-a504-26273944da1e.png)


`CreateWindowExA` accepts [`LPCSTR`](https://docs.microsoft.com/en-us/openspecs/windows_protocols/ms-dtyp/f8d4fe46-6be8-44c9-8823-615a21d17a61) data type as the title, on the other hand, `CreateWindowExW` accepts [`LPCWSTR`](https://docs.microsoft.com/en-us/openspecs/windows_protocols/ms-dtyp/76f10dd8-699d-45e6-a53c-5aefc586da20) as the title. We can simply place an `L` in front of the char array/string to convert `LPCSTR` to `LPCWSTR`.
