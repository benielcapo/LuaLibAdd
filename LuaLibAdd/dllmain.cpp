extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

// Example function: add two numbers
static int l_add(lua_State* L) {
    double a = luaL_checknumber(L, 1);
    double b = luaL_checknumber(L, 2);
    lua_pushnumber(L, a + b);
    return 1;  // number of return values
}

// Register functions
static const struct luaL_Reg mylib_funcs[] = {
    {"add", l_add},
    {NULL, NULL}
};

extern "C" __declspec(dllexport) int luaopen_mylib(lua_State* L) {  
  luaL_newlib(L, mylib_funcs);  
  return 1;  // one value (the new table) returned  
}