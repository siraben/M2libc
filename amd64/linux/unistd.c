/* Copyright (C) 2020 Jeremiah Orians
 * This file is part of M2-Planet.
 *
 * M2-Planet is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * M2-Planet is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with M2-Planet.  If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef _UNISTD_C
#define _UNISTD_C
#include <sys/utsname.h>
#define NULL 0
#define __PATH_MAX 4096

void* malloc(unsigned size);

int access(char* pathname, int mode)
{
	asm("lea rdi, [rsp+16]"
	    "mov rdi, [rdi]"
	    "lea rsi, [rsp+8]"
	    "mov rsi, [rsi]"
	    "mov rax, 21"
	    "syscall");
}

int chdir(char* path)
{
	asm("lea rdi, [rsp+8]"
	    "mov rdi, [rdi]"
	    "mov rax, 80"
	    "syscall");
}

int fchdir(int fd)
{
	asm("lea rdi, [rsp+8]"
	    "mov rdi, [rdi]"
	    "mov rax, 81"
	    "syscall");
}

void _exit(int value);

int fork()
{
	asm("mov rax, 57"
	    "mov rdi, 0"
	    "syscall");
}


int waitpid (int pid, int* status_ptr, int options)
{
	/* Uses wait4 with struct rusage *ru set to NULL */
	asm("lea rdi, [rsp+24]"
	    "mov rdi, [rdi]"
	    "lea rsi, [rsp+16]"
	    "mov rsi, [rsi]"
	    "lea rdx, [rsp+8]"
	    "mov rdx, [rdx]"
	    "mov r10, 0"
	    "mov rax, 61"
	    "syscall");
}


int execve(char* file_name, char** argv, char** envp)
{
	asm("lea rdi, [rsp+24]"
	    "mov rdi, [rdi]"
	    "lea rsi, [rsp+16]"
	    "mov rsi, [rsi]"
	    "lea rdx, [rsp+8]"
	    "mov rdx, [rdx]"
	    "mov rax, 59"
	    "syscall");
}

int read(int fd, char* buf, unsigned count)
{ /*maybe*/
	asm("lea rdi, [rsp+24]"
	    "mov rdi, [rdi]"
	    "lea rsi, [rsp+16]"
	    "mov rsi, [rsi]"
	    "lea rdx, [rsp+8]"
	    "mov rdx, [rdx]"
	    "mov rax, 0"
	    "syscall");
}

int write(int fd, char* buf, unsigned count)
{/*maybe*/
	asm("lea rdi, [rsp+24]"
	    "mov rdi, [rdi]"
	    "lea rsi, [rsp+16]"
	    "mov rsi, [rsi]"
	    "lea rdx, [rsp+8]"
	    "mov rdx, [rdx]"
	    "mov rax, 1"
	    "syscall");
}

int lseek(int fd, int offset, int whence)
{
	asm("lea rdi, [rsp+24]"
	    "mov rdi, [rdi]"
	    "lea rsi, [rsp+16]"
	    "mov rsi, [rsi]"
	    "lea rdx, [rsp+8]"
	    "mov rdx, [rdx]"
	    "mov rax, 8"
	    "syscall");
}


int close(int fd)
{
	asm("lea rdi, [rsp+8]"
	    "mov rdi, [rdi]"
	    "mov rax, 3"
	    "syscall");
}


int unlink (char* filename)
{
	asm("lea rdi, [rsp+8]"
	    "mov rdi, [rdi]"
	    "mov rax, 87"
	    "syscall");
}

int symlink(char *path1, char *path2)
{
	asm("lea rdi, [rsp+16]"
	    "mov rdi, [rdi]"
	    "lea rsi, [rsp+8]"
	    "mov rsi, [rsi]"
	    "mov rax, 88"
	    "syscall");
}

int _getcwd(char* buf, int size)
{
	asm("lea rdi, [rsp+16]"
	    "mov rdi, [rdi]"
	    "lea rsi, [rsp+8]"
	    "mov rsi, [rsi]"
	    "mov rax, 79"
	    "syscall");
}


char* getcwd(char* buf, unsigned size)
{
	int c = _getcwd(buf, size);
	if(0 == c) return NULL;
	return buf;
}


char* getwd(char* buf)
{
	return getcwd(buf, __PATH_MAX);
}


char* get_current_dir_name()
{
	return getcwd(malloc(__PATH_MAX), __PATH_MAX);
}


int brk(void *addr)
{
	asm("mov rax, [rsp+8]"
	    "push rax"
	    "mov rax, 12"
	    "pop rbx"
	    "mov rdi, rbx"
	    "syscall");
}

int uname(struct utsname* unameData)
{
	asm("lea rdi, [rsp+8]"
	    "mov rdi, [rdi]"
	    "mov rax, 63"
	    "syscall");
}

int unshare(int flags)
{
	asm("lea rdi, [rsp+8]"
	    "mov rdi, [rdi]"
	    "mov rax, 272"
	    "syscall");
}

int geteuid()
{
	asm("mov rax, 107"
	    "syscall");
}

int getegid()
{
	asm("mov rax, 108"
	    "syscall");
}

int mount(char *source, char *target, char *filesystemtype, SCM mountflags, void *data)
{
	asm("lea rdi, [rsp+40]"
	    "mov rdi, [rdi]"
	    "lea rsi, [rsp+32]"
	    "mov rsi, [rsi]"
	    "lea rdx, [rsp+24]"
	    "mov rdx, [rdx]"
	    "lea r10, [rsp+16]"
	    "mov r10, [r10]"
	    "lea r8, [rsp+8]"
	    "mov r8, [r8]"
	    "mov rax, 165"
	    "syscall");
}

int chroot(char *path)
{
	asm("lea rdi, [rsp+8]"
	    "mov rdi, [rdi]"
	    "mov rax, 161"
	    "syscall");
}

#endif
