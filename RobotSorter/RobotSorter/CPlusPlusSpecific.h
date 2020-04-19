/*
 * CPlusPlusSpecific.h
 *
 * Created: 02-04-2020 09:45:56
 *  Author: jespe
 */ 


#ifndef CPLUSPLUSSPECIFIC_H_
#define CPLUSPLUSSPECIFIC_H_

__extension__ typedef int __guard __attribute__((mode (__DI__)));

extern "C" void __cxa_pure_virtual() { while (1); }

void * operator new(size_t size);
void operator delete(void * ptr);

int __cxa_guard_acquire(__guard *g) {return !*(char *)(g);};
void __cxa_guard_release (__guard *g) {*(char *)g = 1;};
void __cxa_guard_abort (__guard *) {};

void * operator new(size_t size)
{
	return malloc(size);
}

void operator delete(void * ptr)
{
	ptr != NULL ? free(ptr) : void(0);
}

#endif /* CPLUSPLUSSPECIFIC_H_ */