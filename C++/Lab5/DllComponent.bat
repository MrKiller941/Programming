g++ -shared Server/build/MyComponent.o Server/build/App.o -o Server/build/Component.dll -lole32 -loleaut32 -luser32 -Wl,--kill-at

pause