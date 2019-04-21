# Jailbreak Kernel Patches

### Features

- Jailbreak
- Sandbox escape
- Debug settings
- Enable UART
- RPC server
- RPC client in C#

### General Notes
**Only for 4.74 Jailbroken PlayStation 4 consoles!**

The main jkpatch payload utilizes [a port of CTurt's payload sdk](https://github.com/xvortex/ps4-payload-sdk).

If you decide to edit the `resolve` code in the kernel payload, make sure you do not mess with...
```c
void resolve(uint64_t kernbase);
```
... as it is called from `crt0.s`. And changing this will produce errors.

See other branches for other kernel support. I will support latest publically exploited firmware on main branch.

### RPC Quickstart

See either [Example.cs](librpc/Example.cs) or look at the [RPC documentation](librpc/jkpatch.pdf).

You can read/write memory, call functions, read/write kernel memory, and even load elfs.

[Here](https://www.youtube.com/watch?v=ieQPY4feBZo) is a cool example of an elf loaded into COD Ghosts (forge mod made by me!) You can download the source code to the forge mod [here](http://www.mediafire.com/file/v2m6513km68vmpd/forge.zip). Have fun!

---

Thank you to ChendoChap, idc, zecoxao, hitodama, osdev.org, and anyone else I forgot!


Twitter: [@goldfitzgerald](https://twitter.com/goldfitzgerald) psxhax: [g991](https://www.psxhax.com/members/g991.473299/)

**golden <3**