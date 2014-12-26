#ifndef _DICT_H_
#define _DICT_H_

#include <windows.h>

#define ENTRIES 67
#define ID_QUIT 100
#define ID_MAIN 101
#define ID_SUB 102
#define ID_EDIT 103

typedef struct
{
    LPCWSTR inst;
}Entry;

typedef struct
{
    int numOps;
    char ops[25][25];
    char desc[25][5000];
}Sub;

Entry Dictionary[ENTRIES]={
    L"adc",L"add",L"and",L"bit",L"call",L"ccf",L"cp",L"cpd",L"cpdr",L"cpi", //10
    L"cpir",L"cpl",L"daa",L"dec",L"di",L"djnz",L"ei",L"ex",L"exx",L"halt", //10
    L"im",L"in",L"inc",L"ind",L"indr",L"ini",L"inir",L"jp",L"jr",L"ld", //10
    L"ldd",L"lddr",L"ldi",L"ldir",L"neg",L"nop",L"or",L"out",L"outd",L"otdr", //10
    L"outi",L"otir",L"pop",L"push",L"res",L"ret",L"reti",L"retn",L"rl",L"rla", //10
    L"rlc",L"rlca",L"rld",L"rr",L"rra",L"rrc",L"rrca",L"rrd",L"rst",L"sbc", //10
    L"scf",L"set",L"sla",L"sra",L"srl",L"sub",L"xor" //7
};

Sub Nfo[ENTRIES]={
	{5,{"A,<data>","A,<reg>","A,(HL)","A,(I*)","HL,<rp>"},
    {"Add data to accumulator with carry. Size=2, Clocks=7",
    "Add register to accumulator with carry. Size=1, Clocks=4",
    "Add indirect memory to accumulator with carry. Size=1, Clocks=7",
    "Add indirect memory to accumulator with carry. Size=3, Clocks=19",
    "Add register pair to HL with carry. Size=2, Clocks=15"}},

	{6,{"A,<data>","A,<reg>","A,(HL)","A,(I*)","HL,<rp>","I?,<rp>"},
    {"Add data to accumulator. Size=2, Clocks=7",
    "Add register to accumulator. Size=1, Clocks=4",
    "Add indirect memory to accumulator. Size=1, Clocks=7",
    "Add indirect memory to accumulator. Size=3, Clocks=19",
    "Add register pair to HL. Size=2, Clocks=15",
    "Add register pair to index register. Size=2, Clocks=15"}},

 	{4,{"<data>","<reg>","(HL)","(I*)"},
    {"And data with accumulator. Size=2, Clocks=7",
    "And register with accumulator. Size=1, Clocks=4",
    "And memory with accumulator. Size=1, Clocks=7",
    "And memory with accumulator. Size=3, Clocks=19"}},

 	{3,{"<bit>,<reg>","<b>,(HL)","<b>,(I*)"},
    {"Test <bit> in register. Size=2, Clocks=8",
    "Test <bit> in indirect memory. Size=2, Clocks=12",
    "Test <bit> in indirect memory. Size=4, Clocks=20"}},

 	{2,{"<addr>","<cond>,<addr>"},
    {"Call the routine at <addr>. Size=3, Clocks=17",
    "Call the routine if condition is satisfied. Size=3, Clocks=17"}},

 	{1,{"NONE"},{"Complement carry flag. Size=1, Clocks=4"}},

 	{4,{"<data>","<reg>","(HL)","(I*)"},
    {"Compare data with accumulator. Size=2, Clocks=7",
    "Compare register with accumulator. Size=1, Clocks=4",
    "Compare indirect memory with accumulator. Size=1, Clocks=7",
    "Compare indirect memory with accumulator. Size=3, Clocks=19"}},

 	{1,{"NONE"},{"Compare accumulator with memory and decrement address and byte counter. Size=2, Clocks=16"}},
 	{1,{"NONE"},{"Compare accumulator with memory and decrement address and byte counter; continue until match is found or byte counter is zero. Size=2, Clocks=21"}},
 	{1,{"NONE"},{"Compare accumulator with memory and increment address and byte counter. Size=2, Clocks=16"}},
 	{1,{"NONE"},{"Compare accumulator with memory and increment address and byte counter; continue until match is found or byte counter is zero. Size=2, Clocks=21"}},
 	
 	{1,{"NONE"},{"Complement the accumulator. Size=1, Clocks=4"}},

 	{1,{"NONE"},{"Decimal adjust accumulator. Size=1, Clocks=4"}},

	{5,{"<reg>","<rp>","I?","(HL)","(I*)"},
    {"Decrement register contents. Size=1, Clocks=4",
    "Decrement register pair contents. Size=1, Clocks=6",
    "Decrement index register. Size=2, Clocks=10",
    "Decrement indirect memory contents. Size=3, Clocks=23",
    "Decrement indirect memory contents. Size=2, Clocks=15"}},

 	{1,{"NONE"},{"Disable interrupts. Size=1, Clocks=4"}},

 	{1,{"<addr>"},{"Decrement register B and jump relative if zero. Size=1, Clocks=13"}},

 	{1,{"NONE"},{"Enable interrupts. Size=1, Clocks=4"}},

	{4,{"AF,AF'","DE,HL","(SP),HL","(SP),I?"},
    {"Exchange program status and alt program status. Size=1, Clocks=4",
    "Exchange DE and HL contents. Size=1, Clocks=4",
    "Exchange contents of HL and top of stack. Size=1, Clocks=19",
    "Exchange contents of I? and top of stack. Size=2, Clocks=23"}},
 	{1,{"NONE"},{"Exchange register pairs and alt reg pairs. Size=1, Clocks=4"}},

 	{1,{"NONE"},{"Program execution stops. Size=1, Clocks=4"}},
 	
 	{1,{"<n>"},{"Interrupt mode n. Size=2, Clocks=8"}},

 	{2,{"A,<port>","<reg>,(C)"},
     {"Input port to accumulator. Size=2, Clocks=11",
     "Input to register. Size=2, Clocks=12"}},

	{5,{"<reg>","<rp>","I?","(HL)","(I*)"},
    {"Increment register contents. Size=1, Clocks=4",
    "Increment register pair contents. Size=1, Clocks=6",
    "Increment index register. Size=2, Clocks=10",
    "Increment indirect memory contents. Size=1, Clocks=11",
    "Increment indirect memory contents. Size=3, Clocks=23"}},

	{1,{"NONE"},{"Input to memory and decrement pointer. Size=2, Clocks=16"}},
	
	{1,{"NONE"},{"Input to memory and decrement pointer until byte counter is zero. Size=2, Clocks=21"}},

	{1,{"NONE"},{"Input to memory and increment pointer. Size=2, Clocks=16"}},

	{1,{"NONE"},{"Input to memory and increment pointer until byte counter is zero. Size=2, Clocks=21"}},

	{4,{"<addr>","<cond>,<addr>","(HL)","(I?)"},
    {"Jump to location. Size=3, Clocks=10",
    "Jump to location if condition is satisifed. Size=3, Clocks=10",
    "Jump to location pointed to by HL. Size=1, Clocks=4",
    "Jump to location pointed to by I?. Size=2, Clocks=8"}},

	{2,{"<addr>","<cond>,<addr>"},
    {"Jump relative. Size=2, Clocks=12",
    "Jump relative if condition is satisifed. Size=2, Clocks=12"}},

	{24,{"<reg>,<data>","<reg>,<reg>","<reg>,(HL)","<reg>,(I*)",
    "A,I","A,R","A,(<addr>)","A,(<rp>)","I,A","R,A","<rp>,<data16>",
    "<rp>,(<addr>)","HL,(<addr>)","I?,<data16>","SP,HL","SP,I?",
    "(<addr>),A","(<addr>),HL","(<addr>),<rp>","(<rp>),A",
    "(HL),<data>","(HL),<reg>","(I*),<data>","(I*),<reg>"},
    {"Load register with data. Size=2, Clocks=7",
    "Load source register to destination register. Size=1, Clocks=4",
    "Load register indirect from memory. Size=1, Clocks=7",
    "Load register indirect from memory. Size=3, Clocks=19",
    "Move interrupt vector contents to accumulator. Size=2, Clocks=9",
    "Move refresh register contents to accumulator. Size=2, Clocks=9",
    "Load accumulator indirect from memory. Size=3, Clocks=13",
    "Load accumulator indirect from memory by <rp>. Size=1, Clocks=7",
    "Load interrup vector from accumulator. Size=2, Clocks=9",
    "Load refresh register from accumulator. Size=2, Clocks=9",
    "Load register pair with data. Size=3, Clocks=10",
    "Load register pair indirect from memory. Size=4, Clocks=20",
    "Load HL indirect from memory. Size=3, Clocks=20",
    "Load I? with data. Size=4, Clocks=14",
    "Load contents of HL to stack pointer. Size=1, Clocks=6",
    "Load contents of I? to stack pointer. Size=2, Clocks=10",
    "Load contents of A to memory. Size=3, Clocks=13",
    "Load contents of HL to memory. Size=3, Clocks=16",
    "Load contents of register pair to memory. Size=4, Clocks=20",
    "Load accumulator into indirect memory. Size=1, Clocks=7",
    "Load data into indirect memory. Size=2, Clocks=10",
    "Load register into indirect memory. Size=1, Clocks=7",
    "Load data into indirect memory. Size=4, Clocks=19",
    "Load register into indirect memory. Size=3, Clocks=19"}},

	{1,{"NONE"},{"Transfer data between memory and decrement destination and source addresses. Size=2, Clocks=16"}},

	{1,{"NONE"},{"Transfer data between memory until byte counter is zero, decrement destintation and source addresses. Size=2, Clocks=21"}},

	{1,{"NONE"},{"Transfer data between memory and increment destination and source addresses. Size=2, Clocks=16"}},

	{1,{"NONE"},{"Transfer data between memory until byte counter is zero, increment destintation and source addresses. Size=2, Clocks=21"}},

	{1,{"NONE"},{"Negate contents of accumulator. Size=2, Clocks=8"}},

	{1,{"NONE"},{"No operation. Size=1, Clocks=4"}},

	{4,{"<data>","<reg>","(HL)","(I*)"},
    {"Or data with accumulator. Size=2, Clocks=7",
    "Or register with accumulator. Size=1, Clocks=4"
    "Or indirect memory with accumulator. Size=1, Clocks=7"
    "Or indirect memory with accumulator. Size=3, Clocks=19"}},

	{2,{"<port>,A","(C),<reg>"},
    {"Output from accumulator. Size=2, Clocks=11",
    "Output from register. Size=2, Clocks=12"}},

	{1,{"NONE"},{"Output from memory, decrement address. Size=2, Clocks=16"}},

	{1,{"NONE"},{"Output from memory, decrement address; continue until register B is zero. Size=2, Clocks=21"}},

	{1,{"NONE"},{"Output from memory, increment address. Size=2, Clocks=16"}},

	{1,{"NONE"},{"Output from memory, increment address; continue until register B is zero. Size=2, Clocks=21"}},

	{2,{"<rp>","I?"},
    {"Load register pair from top of stack. Size=1, Clocks=10",
    "Load I? from top of stack. Size=2, Clocks=14"}},

	{2,{"<rp>","I?"},
    {"Store register pair on top of stack. Size=1, Clocks=11",
    "Store I? on top of stack. Size=2, Clocks=15"}},

	{3,{"<bit>,<reg>","<bit>,(HL)","<bit>,(I*)"},
    {"Reset register bit. Size=2, Clocks=8",
    "Reset bit at indirect memory location. Size=2, Clocks=15",
    "Reset bit at indirect memory location. Size=4, Clocks=23",}},

	{2,{"NONE","<cond>"},
    {"Return from subroutine. Size=1, Clocks=10",
    "Return from subroutine if condition true. Size=1, Clocks=11"}},

	{1,{"NONE"},{"Return from interrupt. Size=2, Clocks=14"}},

	{1,{"NONE"},{"Return from non-maskable interrupt. Size=2, Clocks=14"}},

	{3,{"<reg>","(HL)","(I*)"},
    {"Rotate left through carry register contents. Size=2, Clocks=8",
    "Rotate left through carry indirect memory. Size=2, Clocks=15",
    "Rotate left through carry indirect memory. Size=4, Clocks=23"}},

	{1,{"NONE"},{"Rotate left through carry accumulator. Size=1, Clocks=4"}},

	{3,{"<reg>","(HL)","(I*)"},
    {"Rotate left branch carry register contents. Size=2, Clocks=8",
    "Rotate left branch carry indirect memory. Size=2, Clocks=15",
    "Rotate left branch carry indirect memory. Size=4, Clocks=23"}},

	{1,{"NONE"},{"Rotate left accumulator. Size=1, Clocks=4"}},

	{1,{"NONE"},{"Rotate one BCD digit left between the accumulator and memory. Size=2, Clocks=18"}},

	{3,{"<reg>","(HL)","(I*)"},
    {"Rotate right through carry register contents. Size=2, Clocks=8",
    "Rotate right through carry indirect memory. Size=2, Clocks=15",
    "Rotate right through carry indirect memory. Size=4, Clocks=23"}},

	{1,{"NONE"},{"Rotate right through carry accumulator. Size=1, Clocks=4"}},

	{3,{"<reg>","(HL)","(I*)"},
    {"Rotate right branch carry register contents. Size=2, Clocks=8",
    "Rotate right branch carry indirect memory. Size=2, Clocks=15",
    "Rotate right branch carry indirect memory. Size=4, Clocks=23"}},

	{1,{"NONE"},{"Rotate right branch carry accumulator. Size=1, Clocks=4"}},

	{1,{"NONE"},{"Rotate one BCD digit right between the accumulator and memory. Size=2, Clocks=18"}},

	{1,{"NONE"},{"Restart. Size=1, Clocks=11"}},

	{5,{"A,<reg>","A,<data>","A,(HL)","A,(I*)","HL,<rp>"},
    {"Subtract register from accumulator with borrow. Size=1, Clocks=4",
    "Subtract data from accumulator with borrow. Size=2, Clocks=7",
    "Subtract indirect memory from accumulator with borrow. Size=1, Clocks=7",
    "Subtract indirect memory from accumulator with borrow. Size=3, Clocks=19",
    "Subtract register pair from HL with borrow. Size=2, Clocks=15"}},

	{1,{"NONE"},{"Set carry flag. Size=1, Clocks=4"}},

	{3,{"<bit>,<reg>","<bit>,(HL)","<bit>,(I*)"},
    {"Set register bit. Size=2, Clocks=8",
    "Set indirect memory bit. Size=2, Clocks=15",
    "Set indirect memory bit. Size=4, Clocks=23"}},

	{3,{"<reg>","(HL)","(I*)"},
    {"Shift register left arithmetic. Size=2, Clocks=8",
    "Shift indirect memory left arithmetic. Size=2, Clocks=15",
    "Shift indirect memory left arithmetic. Size=4, Clocks=23"}},

	{3,{"<reg>","(HL)","(I*)"},
    {"Shift register right arithmetic. Size=2, Clocks=8",
    "Shift indirect memory right arithmetic. Size=2, Clocks=15",
    "Shift indirect memory right arithmetic. Size=4, Clocks=23"}},

	{3,{"<reg>","(HL)","(I*)"},
    {"Shift register right logical. Size=2, Clocks=8",
    "Shift indirect memory right logical. Size=2, Clocks=15",
    "Shift indirect memory right logical. Size=4, Clocks=23"}},

	{4,{"<data>","<reg>","(HL)","(I*)"},
    {"Subtract data from accumulator. Size=2, Clocks=7",
    "Subtract register from accumulator. Size=1, Clocks=4",
    "Subtract indirect memory from accumulator. Size=1, Clocks=7",
    "Subtract indirect memory from accumulator. Size=3, Clocks=19"}},

	{4,{"<data>","<reg>","(HL)","(I*)"},
    {"Exclusive or data with accumulator. Size=2, Clocks=7",
    "Exclusive or register with accumulator. Size=1, Clocks=4",
    "Exclusive or indirect memory with accumulator. Size=1, Clocks=7",
    "Exclusive or indirect memory with accumulator. Size=3, Clocks=19"}}
};

#endif // _DICT_H_
