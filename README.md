# SmallPP

SmallPP is an object-oriented framework for C. Like small C++. Small CPP. SmallPP. Ok, I will stop.

## Why?

A couple years ago I've worked in Cubiware (later Rovi later TiVo later Xperi... new year - new owner). We made
software for Set-Top Boxes which was written in C. But it wasn't an ordinary C codebase - we had an object-oriented
framework! And it was great, it has inheritance, polymorphism, interfaces, standard library with data types like
string, hash table, array etc. Super cool stuff.

I thought it would be a cool exercise to try to implement something like that on my own. Of course I will not use any
propertiary code from Cubiware. I don't have it, I don't remember most of it - and even if I did, I would break a license.

## Features

Currently implemented features:

* single object inheritance
  * virtual function calls
  * ability to check if object is an instance of another object

## Building

This project uses CMake as a build system. First build the CMake files:

```
cmake -S . -B <output_folder_path>
```

And then compile with:

```shell
cd <output_folder_path>
make
```

Library and all examples' executables will be build inside your `<output_folder_path>`

---

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO 
THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, 
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE 
OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
