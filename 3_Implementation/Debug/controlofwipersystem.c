
wiper.elf:     file format elf32-littlearm

Sections:
Idx Name          Size      VMA       LMA       File off  Algn
  0 .isr_vector   00000188  08000000  08000000  00010000  2**0
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  1 .text         00002010  08000188  08000188  00010188  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, CODE
  2 .rodata       00000000  08002198  08002198  00020004  2**0
                  CONTENTS, ALLOC, LOAD, DATA
  3 .ARM.extab    00000000  08002198  08002198  00020004  2**0
                  CONTENTS
  4 .ARM          00000000  08002198  08002198  00020004  2**0
                  CONTENTS
  5 .preinit_array 00000000  08002198  08002198  00020004  2**0
                  CONTENTS, ALLOC, LOAD, DATA
  6 .init_array   00000004  08002198  08002198  00012198  2**2
                  CONTENTS, ALLOC, LOAD, DATA
  7 .fini_array   00000004  0800219c  0800219c  0001219c  2**2
                  CONTENTS, ALLOC, LOAD, DATA
  8 .data         00000004  20000000  080021a0  00020000  2**0
                  CONTENTS, ALLOC, LOAD, DATA
  9 .ccmram       00000000  10000000  10000000  00020004  2**0
                  CONTENTS
 10 .bss          00000324  20000004  20000004  00020004  2**2
                  ALLOC
 11 ._user_heap_stack 00000600  20000328  20000328  00020004  2**0
                  ALLOC
 12 .ARM.attributes 00000030  00000000  00000000  00020004  2**0
                  CONTENTS, READONLY
 13 .debug_info   000079cc  00000000  00000000  00020034  2**0
                  CONTENTS, READONLY, DEBUGGING, OCTETS
 14 .debug_abbrev 00001364  00000000  00000000  00027a00  2**0
                  CONTENTS, READONLY, DEBUGGING, OCTETS
 15 .debug_aranges 00000638  00000000  00000000  00028d68  2**3
                  CONTENTS, READONLY, DEBUGGING, OCTETS
 16 .debug_ranges 000005a0  00000000  00000000  000293a0  2**3
                  CONTENTS, READONLY, DEBUGGING, OCTETS
 17 .debug_macro  000021f5  00000000  00000000  00029940  2**0
                  CONTENTS, READONLY, DEBUGGING, OCTETS
 18 .debug_line   00007373  00000000  00000000  0002bb35  2**0
                  CONTENTS, READONLY, DEBUGGING, OCTETS
 19 .debug_str    000c7c14  00000000  00000000  00032ea8  2**0
                  CONTENTS, READONLY, DEBUGGING, OCTETS
 20 .comment      00000050  00000000  00000000  000faabc  2**0
                  CONTENTS, READONLY
 21 .debug_frame  000018e0  00000000  00000000  000fab0c  2**2
                  CONTENTS, READONLY, DEBUGGING, OCTETS

Disassembly of section .text:

08000188 <__do_global_dtors_aux>:
 8000188:	b510      	push	{r4, lr}
 800018a:	4c05      	ldr	r4, [pc, #20]	; (80001a0 <__do_global_dtors_aux+0x18>)
 800018c:	7823      	ldrb	r3, [r4, #0]
 800018e:	b933      	cbnz	r3, 800019e <__do_global_dtors_aux+0x16>
 8000190:	4b04      	ldr	r3, [pc, #16]	; (80001a4 <__do_global_dtors_aux+0x1c>)
 8000192:	b113      	cbz	r3, 800019a <__do_global_dtors_aux+0x12>
 8000194:	4804      	ldr	r0, [pc, #16]	; (80001a8 <__do_global_dtors_aux+0x20>)
 8000196:	f3af 8000 	nop.w
 800019a:	2301      	movs	r3, #1
 800019c:	7023      	strb	r3, [r4, #0]
 800019e:	bd10      	pop	{r4, pc}
 80001a0:	20000004 	.word	0x20000004
 80001a4:	00000000 	.word	0x00000000
 80001a8:	08002180 	.word	0x08002180

080001ac <frame_dummy>:
 80001ac:	b508      	push	{r3, lr}
 80001ae:	4b03      	ldr	r3, [pc, #12]	; (80001bc <frame_dummy+0x10>)
 80001b0:	b11b      	cbz	r3, 80001ba <frame_dummy+0xe>
 80001b2:	4903      	ldr	r1, [pc, #12]	; (80001c0 <frame_dummy+0x14>)
 80001b4:	4803      	ldr	r0, [pc, #12]	; (80001c4 <frame_dummy+0x18>)
 80001b6:	f3af 8000 	nop.w
 80001ba:	bd08      	pop	{r3, pc}
 80001bc:	00000000 	.word	0x00000000
 80001c0:	20000008 	.word	0x20000008
 80001c4:	08002180 	.word	0x08002180

080001c8 <main>:
#define GPIOA_MODE_OFFSET 0x00
#define GPIOA_MODE *(volatile long *)(GPIOA_BASE_ADDR + GPIOA_MODE_OFFSET)


int main()
{
 80001c8:	b480      	push	{r7}
 80001ca:	b085      	sub	sp, #20
 80001cc:	af00      	add	r7, sp, #0
	int i,b=0,j=0;  //Declaring and Initilizing Variables
 80001ce:	2300      	movs	r3, #0
 80001d0:	60bb      	str	r3, [r7, #8]
 80001d2:	2300      	movs	r3, #0
 80001d4:	607b      	str	r3, [r7, #4]
	RCC_AHB1ENR |= (1<<3)|(1<<0); //Enabling the LED and the switch
 80001d6:	4b94      	ldr	r3, [pc, #592]	; (8000428 <main+0x260>)
 80001d8:	681b      	ldr	r3, [r3, #0]
 80001da:	4a93      	ldr	r2, [pc, #588]	; (8000428 <main+0x260>)
 80001dc:	f043 0309 	orr.w	r3, r3, #9
 80001e0:	6013      	str	r3, [r2, #0]
	GPIOD_MODE = 0; //For Clear LED
 80001e2:	4b92      	ldr	r3, [pc, #584]	; (800042c <main+0x264>)
 80001e4:	2200      	movs	r2, #0
 80001e6:	601a      	str	r2, [r3, #0]
	GPIOA_MODE = 0; //For Clear Switch
 80001e8:	4b91      	ldr	r3, [pc, #580]	; (8000430 <main+0x268>)
 80001ea:	2200      	movs	r2, #0
 80001ec:	601a      	str	r2, [r3, #0]
	GPIOA_IDR |= 1<<3;
 80001ee:	4b91      	ldr	r3, [pc, #580]	; (8000434 <main+0x26c>)
 80001f0:	681b      	ldr	r3, [r3, #0]
 80001f2:	4a90      	ldr	r2, [pc, #576]	; (8000434 <main+0x26c>)
 80001f4:	f043 0308 	orr.w	r3, r3, #8
 80001f8:	6013      	str	r3, [r2, #0]
	GPIOD_MODE |= (0<<25)|(1<<24);  //to assign LED 12 as output pin
 80001fa:	4b8c      	ldr	r3, [pc, #560]	; (800042c <main+0x264>)
 80001fc:	681b      	ldr	r3, [r3, #0]
 80001fe:	4a8b      	ldr	r2, [pc, #556]	; (800042c <main+0x264>)
 8000200:	f043 7380 	orr.w	r3, r3, #16777216	; 0x1000000
 8000204:	6013      	str	r3, [r2, #0]
	GPIOD_MODE |= (0<<27)|(1<<26);  //to assign LED 13 as output pin
 8000206:	4b89      	ldr	r3, [pc, #548]	; (800042c <main+0x264>)
 8000208:	681b      	ldr	r3, [r3, #0]
 800020a:	4a88      	ldr	r2, [pc, #544]	; (800042c <main+0x264>)
 800020c:	f043 6380 	orr.w	r3, r3, #67108864	; 0x4000000
 8000210:	6013      	str	r3, [r2, #0]
	GPIOD_MODE |= (0<<29)|(1<<28);  //to assign LED 14 as output pin
 8000212:	4b86      	ldr	r3, [pc, #536]	; (800042c <main+0x264>)
 8000214:	681b      	ldr	r3, [r3, #0]
 8000216:	4a85      	ldr	r2, [pc, #532]	; (800042c <main+0x264>)
 8000218:	f043 5380 	orr.w	r3, r3, #268435456	; 0x10000000
 800021c:	6013      	str	r3, [r2, #0]
	GPIOD_MODE |= (0<<31)|(1<<30);  //to assign LED 14 as output pin as per the Datasheet
 800021e:	4b83      	ldr	r3, [pc, #524]	; (800042c <main+0x264>)
 8000220:	681b      	ldr	r3, [r3, #0]
 8000222:	4a82      	ldr	r2, [pc, #520]	; (800042c <main+0x264>)
 8000224:	f043 4380 	orr.w	r3, r3, #1073741824	; 0x40000000
 8000228:	6013      	str	r3, [r2, #0]
	GPIOA_MODE |= (0<<1)|(0<<0);    //to assign Switch as input pin as per the Datasheet
 800022a:	4b81      	ldr	r3, [pc, #516]	; (8000430 <main+0x268>)
 800022c:	4a80      	ldr	r2, [pc, #512]	; (8000430 <main+0x268>)
 800022e:	681b      	ldr	r3, [r3, #0]
 8000230:	6013      	str	r3, [r2, #0]
	GPIOD_ODR = 0X00;
 8000232:	4b81      	ldr	r3, [pc, #516]	; (8000438 <main+0x270>)
 8000234:	2200      	movs	r2, #0
 8000236:	601a      	str	r2, [r3, #0]
	while(1)
	{
					while((GPIOA_IDR & 0x01) == 1) // Switch Status On
 8000238:	e002      	b.n	8000240 <main+0x78>
					{
						b++; //Increment for Switch
 800023a:	68bb      	ldr	r3, [r7, #8]
 800023c:	3301      	adds	r3, #1
 800023e:	60bb      	str	r3, [r7, #8]
					while((GPIOA_IDR & 0x01) == 1) // Switch Status On
 8000240:	4b7c      	ldr	r3, [pc, #496]	; (8000434 <main+0x26c>)
 8000242:	681b      	ldr	r3, [r3, #0]
 8000244:	f003 0301 	and.w	r3, r3, #1
 8000248:	2b01      	cmp	r3, #1
 800024a:	d0f6      	beq.n	800023a <main+0x72>
					}
					if(b>30000)
 800024c:	68bb      	ldr	r3, [r7, #8]
 800024e:	f247 5230 	movw	r2, #30000	; 0x7530
 8000252:	4293      	cmp	r3, r2
 8000254:	dd12      	ble.n	800027c <main+0xb4>
				    {
					b=0;//RED Led should be in ON state
 8000256:	2300      	movs	r3, #0
 8000258:	60bb      	str	r3, [r7, #8]
					GPIOD_ODR |= 1<<14;
 800025a:	4b77      	ldr	r3, [pc, #476]	; (8000438 <main+0x270>)
 800025c:	681b      	ldr	r3, [r3, #0]
 800025e:	4a76      	ldr	r2, [pc, #472]	; (8000438 <main+0x270>)
 8000260:	f443 4380 	orr.w	r3, r3, #16384	; 0x4000
 8000264:	6013      	str	r3, [r2, #0]
					for(i=0;i<100000;i++);
 8000266:	2300      	movs	r3, #0
 8000268:	60fb      	str	r3, [r7, #12]
 800026a:	e002      	b.n	8000272 <main+0xaa>
 800026c:	68fb      	ldr	r3, [r7, #12]
 800026e:	3301      	adds	r3, #1
 8000270:	60fb      	str	r3, [r7, #12]
 8000272:	68fb      	ldr	r3, [r7, #12]
 8000274:	4a71      	ldr	r2, [pc, #452]	; (800043c <main+0x274>)
 8000276:	4293      	cmp	r3, r2
 8000278:	ddf8      	ble.n	800026c <main+0xa4>
 800027a:	e009      	b.n	8000290 <main+0xc8>
					}
					else if(b>0 && b<30000)
 800027c:	68bb      	ldr	r3, [r7, #8]
 800027e:	2b00      	cmp	r3, #0
 8000280:	dd06      	ble.n	8000290 <main+0xc8>
 8000282:	68bb      	ldr	r3, [r7, #8]
 8000284:	f247 522f 	movw	r2, #29999	; 0x752f
 8000288:	4293      	cmp	r3, r2
 800028a:	dc01      	bgt.n	8000290 <main+0xc8>
					{
					j=1;
 800028c:	2301      	movs	r3, #1
 800028e:	607b      	str	r3, [r7, #4]
                    }
					else
					{

					}
						if(j==1)
 8000290:	687b      	ldr	r3, [r7, #4]
 8000292:	2b01      	cmp	r3, #1
 8000294:	d1d4      	bne.n	8000240 <main+0x78>
						{

					    //By using Fast Frequency delay

				        for(j=0;j<5;j++) //For LED GREEN
 8000296:	2300      	movs	r3, #0
 8000298:	607b      	str	r3, [r7, #4]
 800029a:	e024      	b.n	80002e6 <main+0x11e>
						{
						GPIOD_ODR |= 1<<12;
 800029c:	4b66      	ldr	r3, [pc, #408]	; (8000438 <main+0x270>)
 800029e:	681b      	ldr	r3, [r3, #0]
 80002a0:	4a65      	ldr	r2, [pc, #404]	; (8000438 <main+0x270>)
 80002a2:	f443 5380 	orr.w	r3, r3, #4096	; 0x1000
 80002a6:	6013      	str	r3, [r2, #0]
						for(i=0;i<20000;i++);
 80002a8:	2300      	movs	r3, #0
 80002aa:	60fb      	str	r3, [r7, #12]
 80002ac:	e002      	b.n	80002b4 <main+0xec>
 80002ae:	68fb      	ldr	r3, [r7, #12]
 80002b0:	3301      	adds	r3, #1
 80002b2:	60fb      	str	r3, [r7, #12]
 80002b4:	68fb      	ldr	r3, [r7, #12]
 80002b6:	f644 621f 	movw	r2, #19999	; 0x4e1f
 80002ba:	4293      	cmp	r3, r2
 80002bc:	ddf7      	ble.n	80002ae <main+0xe6>
						GPIOD_ODR &= ~(1<<12);
 80002be:	4b5e      	ldr	r3, [pc, #376]	; (8000438 <main+0x270>)
 80002c0:	681b      	ldr	r3, [r3, #0]
 80002c2:	4a5d      	ldr	r2, [pc, #372]	; (8000438 <main+0x270>)
 80002c4:	f423 5380 	bic.w	r3, r3, #4096	; 0x1000
 80002c8:	6013      	str	r3, [r2, #0]
						for(i=0;i>=20000;i++);
 80002ca:	2300      	movs	r3, #0
 80002cc:	60fb      	str	r3, [r7, #12]
 80002ce:	e002      	b.n	80002d6 <main+0x10e>
 80002d0:	68fb      	ldr	r3, [r7, #12]
 80002d2:	3301      	adds	r3, #1
 80002d4:	60fb      	str	r3, [r7, #12]
 80002d6:	68fb      	ldr	r3, [r7, #12]
 80002d8:	f644 621f 	movw	r2, #19999	; 0x4e1f
 80002dc:	4293      	cmp	r3, r2
 80002de:	dcf7      	bgt.n	80002d0 <main+0x108>
				        for(j=0;j<5;j++) //For LED GREEN
 80002e0:	687b      	ldr	r3, [r7, #4]
 80002e2:	3301      	adds	r3, #1
 80002e4:	607b      	str	r3, [r7, #4]
 80002e6:	687b      	ldr	r3, [r7, #4]
 80002e8:	2b04      	cmp	r3, #4
 80002ea:	ddd7      	ble.n	800029c <main+0xd4>
						}
						for(j=0;j<5;j++)  //For LED ORANGE
 80002ec:	2300      	movs	r3, #0
 80002ee:	607b      	str	r3, [r7, #4]
 80002f0:	e024      	b.n	800033c <main+0x174>
						{
						GPIOD_ODR |= 1<<13;
 80002f2:	4b51      	ldr	r3, [pc, #324]	; (8000438 <main+0x270>)
 80002f4:	681b      	ldr	r3, [r3, #0]
 80002f6:	4a50      	ldr	r2, [pc, #320]	; (8000438 <main+0x270>)
 80002f8:	f443 5300 	orr.w	r3, r3, #8192	; 0x2000
 80002fc:	6013      	str	r3, [r2, #0]
						for(i=0;i<20000;i++);
 80002fe:	2300      	movs	r3, #0
 8000300:	60fb      	str	r3, [r7, #12]
 8000302:	e002      	b.n	800030a <main+0x142>
 8000304:	68fb      	ldr	r3, [r7, #12]
 8000306:	3301      	adds	r3, #1
 8000308:	60fb      	str	r3, [r7, #12]
 800030a:	68fb      	ldr	r3, [r7, #12]
 800030c:	f644 621f 	movw	r2, #19999	; 0x4e1f
 8000310:	4293      	cmp	r3, r2
 8000312:	ddf7      	ble.n	8000304 <main+0x13c>
						GPIOD_ODR &= ~(1<<13);
 8000314:	4b48      	ldr	r3, [pc, #288]	; (8000438 <main+0x270>)
 8000316:	681b      	ldr	r3, [r3, #0]
 8000318:	4a47      	ldr	r2, [pc, #284]	; (8000438 <main+0x270>)
 800031a:	f423 5300 	bic.w	r3, r3, #8192	; 0x2000
 800031e:	6013      	str	r3, [r2, #0]
					    for(i=0;i>=20000;i++);
 8000320:	2300      	movs	r3, #0
 8000322:	60fb      	str	r3, [r7, #12]
 8000324:	e002      	b.n	800032c <main+0x164>
 8000326:	68fb      	ldr	r3, [r7, #12]
 8000328:	3301      	adds	r3, #1
 800032a:	60fb      	str	r3, [r7, #12]
 800032c:	68fb      	ldr	r3, [r7, #12]
 800032e:	f644 621f 	movw	r2, #19999	; 0x4e1f
 8000332:	4293      	cmp	r3, r2
 8000334:	dcf7      	bgt.n	8000326 <main+0x15e>
						for(j=0;j<5;j++)  //For LED ORANGE
 8000336:	687b      	ldr	r3, [r7, #4]
 8000338:	3301      	adds	r3, #1
 800033a:	607b      	str	r3, [r7, #4]
 800033c:	687b      	ldr	r3, [r7, #4]
 800033e:	2b04      	cmp	r3, #4
 8000340:	ddd7      	ble.n	80002f2 <main+0x12a>
						}
						for(j=0;j<5;j++)   //For LED BLUE
 8000342:	2300      	movs	r3, #0
 8000344:	607b      	str	r3, [r7, #4]
 8000346:	e024      	b.n	8000392 <main+0x1ca>
						{
						GPIOD_ODR |= 1<<15;
 8000348:	4b3b      	ldr	r3, [pc, #236]	; (8000438 <main+0x270>)
 800034a:	681b      	ldr	r3, [r3, #0]
 800034c:	4a3a      	ldr	r2, [pc, #232]	; (8000438 <main+0x270>)
 800034e:	f443 4300 	orr.w	r3, r3, #32768	; 0x8000
 8000352:	6013      	str	r3, [r2, #0]
						for(i=0;i<20000;i++);
 8000354:	2300      	movs	r3, #0
 8000356:	60fb      	str	r3, [r7, #12]
 8000358:	e002      	b.n	8000360 <main+0x198>
 800035a:	68fb      	ldr	r3, [r7, #12]
 800035c:	3301      	adds	r3, #1
 800035e:	60fb      	str	r3, [r7, #12]
 8000360:	68fb      	ldr	r3, [r7, #12]
 8000362:	f644 621f 	movw	r2, #19999	; 0x4e1f
 8000366:	4293      	cmp	r3, r2
 8000368:	ddf7      	ble.n	800035a <main+0x192>
						GPIOD_ODR &= ~(1<<15);
 800036a:	4b33      	ldr	r3, [pc, #204]	; (8000438 <main+0x270>)
 800036c:	681b      	ldr	r3, [r3, #0]
 800036e:	4a32      	ldr	r2, [pc, #200]	; (8000438 <main+0x270>)
 8000370:	f423 4300 	bic.w	r3, r3, #32768	; 0x8000
 8000374:	6013      	str	r3, [r2, #0]
						for(i=0;i>=20000;i++);
 8000376:	2300      	movs	r3, #0
 8000378:	60fb      	str	r3, [r7, #12]
 800037a:	e002      	b.n	8000382 <main+0x1ba>
 800037c:	68fb      	ldr	r3, [r7, #12]
 800037e:	3301      	adds	r3, #1
 8000380:	60fb      	str	r3, [r7, #12]
 8000382:	68fb      	ldr	r3, [r7, #12]
 8000384:	f644 621f 	movw	r2, #19999	; 0x4e1f
 8000388:	4293      	cmp	r3, r2
 800038a:	dcf7      	bgt.n	800037c <main+0x1b4>
						for(j=0;j<5;j++)   //For LED BLUE
 800038c:	687b      	ldr	r3, [r7, #4]
 800038e:	3301      	adds	r3, #1
 8000390:	607b      	str	r3, [r7, #4]
 8000392:	687b      	ldr	r3, [r7, #4]
 8000394:	2b04      	cmp	r3, #4
 8000396:	ddd7      	ble.n	8000348 <main+0x180>
						}

						//Medium Speed Delay

						for(j=0;j<5;j++)  //For LED GREEN
 8000398:	2300      	movs	r3, #0
 800039a:	607b      	str	r3, [r7, #4]
 800039c:	e024      	b.n	80003e8 <main+0x220>
						{
						GPIOD_ODR |= 1<<12;
 800039e:	4b26      	ldr	r3, [pc, #152]	; (8000438 <main+0x270>)
 80003a0:	681b      	ldr	r3, [r3, #0]
 80003a2:	4a25      	ldr	r2, [pc, #148]	; (8000438 <main+0x270>)
 80003a4:	f443 5380 	orr.w	r3, r3, #4096	; 0x1000
 80003a8:	6013      	str	r3, [r2, #0]
						for(i=0;i<40000;i++);
 80003aa:	2300      	movs	r3, #0
 80003ac:	60fb      	str	r3, [r7, #12]
 80003ae:	e002      	b.n	80003b6 <main+0x1ee>
 80003b0:	68fb      	ldr	r3, [r7, #12]
 80003b2:	3301      	adds	r3, #1
 80003b4:	60fb      	str	r3, [r7, #12]
 80003b6:	68fb      	ldr	r3, [r7, #12]
 80003b8:	f649 423f 	movw	r2, #39999	; 0x9c3f
 80003bc:	4293      	cmp	r3, r2
 80003be:	ddf7      	ble.n	80003b0 <main+0x1e8>
						GPIOD_ODR &= ~(1<<12);
 80003c0:	4b1d      	ldr	r3, [pc, #116]	; (8000438 <main+0x270>)
 80003c2:	681b      	ldr	r3, [r3, #0]
 80003c4:	4a1c      	ldr	r2, [pc, #112]	; (8000438 <main+0x270>)
 80003c6:	f423 5380 	bic.w	r3, r3, #4096	; 0x1000
 80003ca:	6013      	str	r3, [r2, #0]
						for(i=0;i>=40000;i++);
 80003cc:	2300      	movs	r3, #0
 80003ce:	60fb      	str	r3, [r7, #12]
 80003d0:	e002      	b.n	80003d8 <main+0x210>
 80003d2:	68fb      	ldr	r3, [r7, #12]
 80003d4:	3301      	adds	r3, #1
 80003d6:	60fb      	str	r3, [r7, #12]
 80003d8:	68fb      	ldr	r3, [r7, #12]
 80003da:	f649 423f 	movw	r2, #39999	; 0x9c3f
 80003de:	4293      	cmp	r3, r2
 80003e0:	dcf7      	bgt.n	80003d2 <main+0x20a>
						for(j=0;j<5;j++)  //For LED GREEN
 80003e2:	687b      	ldr	r3, [r7, #4]
 80003e4:	3301      	adds	r3, #1
 80003e6:	607b      	str	r3, [r7, #4]
 80003e8:	687b      	ldr	r3, [r7, #4]
 80003ea:	2b04      	cmp	r3, #4
 80003ec:	ddd7      	ble.n	800039e <main+0x1d6>
						}
						for(j=0;j<5;j++)  //For LED ORANGE
 80003ee:	2300      	movs	r3, #0
 80003f0:	607b      	str	r3, [r7, #4]
 80003f2:	e030      	b.n	8000456 <main+0x28e>
						{
						GPIOD_ODR |= 1<<13;
 80003f4:	4b10      	ldr	r3, [pc, #64]	; (8000438 <main+0x270>)
 80003f6:	681b      	ldr	r3, [r3, #0]
 80003f8:	4a0f      	ldr	r2, [pc, #60]	; (8000438 <main+0x270>)
 80003fa:	f443 5300 	orr.w	r3, r3, #8192	; 0x2000
 80003fe:	6013      	str	r3, [r2, #0]
						for(i=0;i<40000;i++);
 8000400:	2300      	movs	r3, #0
 8000402:	60fb      	str	r3, [r7, #12]
 8000404:	e002      	b.n	800040c <main+0x244>
 8000406:	68fb      	ldr	r3, [r7, #12]
 8000408:	3301      	adds	r3, #1
 800040a:	60fb      	str	r3, [r7, #12]
 800040c:	68fb      	ldr	r3, [r7, #12]
 800040e:	f649 423f 	movw	r2, #39999	; 0x9c3f
 8000412:	4293      	cmp	r3, r2
 8000414:	ddf7      	ble.n	8000406 <main+0x23e>
						GPIOD_ODR &= ~(1<<13);
 8000416:	4b08      	ldr	r3, [pc, #32]	; (8000438 <main+0x270>)
 8000418:	681b      	ldr	r3, [r3, #0]
 800041a:	4a07      	ldr	r2, [pc, #28]	; (8000438 <main+0x270>)
 800041c:	f423 5300 	bic.w	r3, r3, #8192	; 0x2000
 8000420:	6013      	str	r3, [r2, #0]
						for(i=0;i>=40000;i++);
 8000422:	2300      	movs	r3, #0
 8000424:	60fb      	str	r3, [r7, #12]
 8000426:	e00e      	b.n	8000446 <main+0x27e>
 8000428:	40023830 	.word	0x40023830
 800042c:	40020c00 	.word	0x40020c00
 8000430:	40020000 	.word	0x40020000
 8000434:	40020010 	.word	0x40020010
 8000438:	40020c14 	.word	0x40020c14
 800043c:	0001869f 	.word	0x0001869f
 8000440:	68fb      	ldr	r3, [r7, #12]
 8000442:	3301      	adds	r3, #1
 8000444:	60fb      	str	r3, [r7, #12]
 8000446:	68fb      	ldr	r3, [r7, #12]
 8000448:	f649 423f 	movw	r2, #39999	; 0x9c3f
 800044c:	4293      	cmp	r3, r2
 800044e:	dcf7      	bgt.n	8000440 <main+0x278>
						for(j=0;j<5;j++)  //For LED ORANGE
 8000450:	687b      	ldr	r3, [r7, #4]
 8000452:	3301      	adds	r3, #1
 8000454:	607b      	str	r3, [r7, #4]
 8000456:	687b      	ldr	r3, [r7, #4]
 8000458:	2b04      	cmp	r3, #4
 800045a:	ddcb      	ble.n	80003f4 <main+0x22c>
						}
						for(j=0;j<5;j++)  //For LED BLUE
 800045c:	2300      	movs	r3, #0
 800045e:	607b      	str	r3, [r7, #4]
 8000460:	e024      	b.n	80004ac <main+0x2e4>
						{
						GPIOD_ODR |= 1<<15;
 8000462:	4b52      	ldr	r3, [pc, #328]	; (80005ac <main+0x3e4>)
 8000464:	681b      	ldr	r3, [r3, #0]
 8000466:	4a51      	ldr	r2, [pc, #324]	; (80005ac <main+0x3e4>)
 8000468:	f443 4300 	orr.w	r3, r3, #32768	; 0x8000
 800046c:	6013      	str	r3, [r2, #0]
						for(i=0;i<40000;i++);
 800046e:	2300      	movs	r3, #0
 8000470:	60fb      	str	r3, [r7, #12]
 8000472:	e002      	b.n	800047a <main+0x2b2>
 8000474:	68fb      	ldr	r3, [r7, #12]
 8000476:	3301      	adds	r3, #1
 8000478:	60fb      	str	r3, [r7, #12]
 800047a:	68fb      	ldr	r3, [r7, #12]
 800047c:	f649 423f 	movw	r2, #39999	; 0x9c3f
 8000480:	4293      	cmp	r3, r2
 8000482:	ddf7      	ble.n	8000474 <main+0x2ac>
					    GPIOD_ODR &= ~(1<<15);
 8000484:	4b49      	ldr	r3, [pc, #292]	; (80005ac <main+0x3e4>)
 8000486:	681b      	ldr	r3, [r3, #0]
 8000488:	4a48      	ldr	r2, [pc, #288]	; (80005ac <main+0x3e4>)
 800048a:	f423 4300 	bic.w	r3, r3, #32768	; 0x8000
 800048e:	6013      	str	r3, [r2, #0]
						for(i=0;i>=40000;i++);
 8000490:	2300      	movs	r3, #0
 8000492:	60fb      	str	r3, [r7, #12]
 8000494:	e002      	b.n	800049c <main+0x2d4>
 8000496:	68fb      	ldr	r3, [r7, #12]
 8000498:	3301      	adds	r3, #1
 800049a:	60fb      	str	r3, [r7, #12]
 800049c:	68fb      	ldr	r3, [r7, #12]
 800049e:	f649 423f 	movw	r2, #39999	; 0x9c3f
 80004a2:	4293      	cmp	r3, r2
 80004a4:	dcf7      	bgt.n	8000496 <main+0x2ce>
						for(j=0;j<5;j++)  //For LED BLUE
 80004a6:	687b      	ldr	r3, [r7, #4]
 80004a8:	3301      	adds	r3, #1
 80004aa:	607b      	str	r3, [r7, #4]
 80004ac:	687b      	ldr	r3, [r7, #4]
 80004ae:	2b04      	cmp	r3, #4
 80004b0:	ddd7      	ble.n	8000462 <main+0x29a>
						}
						//High Speed Delay

						for(j=0;j<5;j++)  //For LED GREEN
 80004b2:	2300      	movs	r3, #0
 80004b4:	607b      	str	r3, [r7, #4]
 80004b6:	e022      	b.n	80004fe <main+0x336>
					    {
						GPIOD_ODR |= 1<<12;
 80004b8:	4b3c      	ldr	r3, [pc, #240]	; (80005ac <main+0x3e4>)
 80004ba:	681b      	ldr	r3, [r3, #0]
 80004bc:	4a3b      	ldr	r2, [pc, #236]	; (80005ac <main+0x3e4>)
 80004be:	f443 5380 	orr.w	r3, r3, #4096	; 0x1000
 80004c2:	6013      	str	r3, [r2, #0]
						for(i=0;i<80000;i++);
 80004c4:	2300      	movs	r3, #0
 80004c6:	60fb      	str	r3, [r7, #12]
 80004c8:	e002      	b.n	80004d0 <main+0x308>
 80004ca:	68fb      	ldr	r3, [r7, #12]
 80004cc:	3301      	adds	r3, #1
 80004ce:	60fb      	str	r3, [r7, #12]
 80004d0:	68fb      	ldr	r3, [r7, #12]
 80004d2:	4a37      	ldr	r2, [pc, #220]	; (80005b0 <main+0x3e8>)
 80004d4:	4293      	cmp	r3, r2
 80004d6:	ddf8      	ble.n	80004ca <main+0x302>
						GPIOD_ODR &= ~(1<<12);
 80004d8:	4b34      	ldr	r3, [pc, #208]	; (80005ac <main+0x3e4>)
 80004da:	681b      	ldr	r3, [r3, #0]
 80004dc:	4a33      	ldr	r2, [pc, #204]	; (80005ac <main+0x3e4>)
 80004de:	f423 5380 	bic.w	r3, r3, #4096	; 0x1000
 80004e2:	6013      	str	r3, [r2, #0]
						for(i=0;i>=80000;i++);
 80004e4:	2300      	movs	r3, #0
 80004e6:	60fb      	str	r3, [r7, #12]
 80004e8:	e002      	b.n	80004f0 <main+0x328>
 80004ea:	68fb      	ldr	r3, [r7, #12]
 80004ec:	3301      	adds	r3, #1
 80004ee:	60fb      	str	r3, [r7, #12]
 80004f0:	68fb      	ldr	r3, [r7, #12]
 80004f2:	4a2f      	ldr	r2, [pc, #188]	; (80005b0 <main+0x3e8>)
 80004f4:	4293      	cmp	r3, r2
 80004f6:	dcf8      	bgt.n	80004ea <main+0x322>
						for(j=0;j<5;j++)  //For LED GREEN
 80004f8:	687b      	ldr	r3, [r7, #4]
 80004fa:	3301      	adds	r3, #1
 80004fc:	607b      	str	r3, [r7, #4]
 80004fe:	687b      	ldr	r3, [r7, #4]
 8000500:	2b04      	cmp	r3, #4
 8000502:	ddd9      	ble.n	80004b8 <main+0x2f0>
						}
						for(j=0;j<5;j++)  //For LED ORANGE
 8000504:	2300      	movs	r3, #0
 8000506:	607b      	str	r3, [r7, #4]
 8000508:	e022      	b.n	8000550 <main+0x388>
						{
						GPIOD_ODR |= 1<<13;
 800050a:	4b28      	ldr	r3, [pc, #160]	; (80005ac <main+0x3e4>)
 800050c:	681b      	ldr	r3, [r3, #0]
 800050e:	4a27      	ldr	r2, [pc, #156]	; (80005ac <main+0x3e4>)
 8000510:	f443 5300 	orr.w	r3, r3, #8192	; 0x2000
 8000514:	6013      	str	r3, [r2, #0]
						for(i=0;i<80000;i++);
 8000516:	2300      	movs	r3, #0
 8000518:	60fb      	str	r3, [r7, #12]
 800051a:	e002      	b.n	8000522 <main+0x35a>
 800051c:	68fb      	ldr	r3, [r7, #12]
 800051e:	3301      	adds	r3, #1
 8000520:	60fb      	str	r3, [r7, #12]
 8000522:	68fb      	ldr	r3, [r7, #12]
 8000524:	4a22      	ldr	r2, [pc, #136]	; (80005b0 <main+0x3e8>)
 8000526:	4293      	cmp	r3, r2
 8000528:	ddf8      	ble.n	800051c <main+0x354>
						GPIOD_ODR &= ~(1<<13);
 800052a:	4b20      	ldr	r3, [pc, #128]	; (80005ac <main+0x3e4>)
 800052c:	681b      	ldr	r3, [r3, #0]
 800052e:	4a1f      	ldr	r2, [pc, #124]	; (80005ac <main+0x3e4>)
 8000530:	f423 5300 	bic.w	r3, r3, #8192	; 0x2000
 8000534:	6013      	str	r3, [r2, #0]
						for(i=0;i>=80000;i++);
 8000536:	2300      	movs	r3, #0
 8000538:	60fb      	str	r3, [r7, #12]
 800053a:	e002      	b.n	8000542 <main+0x37a>
 800053c:	68fb      	ldr	r3, [r7, #12]
 800053e:	3301      	adds	r3, #1
 8000540:	60fb      	str	r3, [r7, #12]
 8000542:	68fb      	ldr	r3, [r7, #12]
 8000544:	4a1a      	ldr	r2, [pc, #104]	; (80005b0 <main+0x3e8>)
 8000546:	4293      	cmp	r3, r2
 8000548:	dcf8      	bgt.n	800053c <main+0x374>
						for(j=0;j<5;j++)  //For LED ORANGE
 800054a:	687b      	ldr	r3, [r7, #4]
 800054c:	3301      	adds	r3, #1
 800054e:	607b      	str	r3, [r7, #4]
 8000550:	687b      	ldr	r3, [r7, #4]
 8000552:	2b04      	cmp	r3, #4
 8000554:	ddd9      	ble.n	800050a <main+0x342>
						}
						for(j=0;j<5;j++)  //For LED BLUE
 8000556:	2300      	movs	r3, #0
 8000558:	607b      	str	r3, [r7, #4]
 800055a:	e022      	b.n	80005a2 <main+0x3da>
						{
						GPIOD_ODR |= 1<<15;
 800055c:	4b13      	ldr	r3, [pc, #76]	; (80005ac <main+0x3e4>)
 800055e:	681b      	ldr	r3, [r3, #0]
 8000560:	4a12      	ldr	r2, [pc, #72]	; (80005ac <main+0x3e4>)
 8000562:	f443 4300 	orr.w	r3, r3, #32768	; 0x8000
 8000566:	6013      	str	r3, [r2, #0]
						for(i=0;i<80000;i++);
 8000568:	2300      	movs	r3, #0
 800056a:	60fb      	str	r3, [r7, #12]
 800056c:	e002      	b.n	8000574 <main+0x3ac>
 800056e:	68fb      	ldr	r3, [r7, #12]
 8000570:	3301      	adds	r3, #1
 8000572:	60fb      	str	r3, [r7, #12]
 8000574:	68fb      	ldr	r3, [r7, #12]
 8000576:	4a0e      	ldr	r2, [pc, #56]	; (80005b0 <main+0x3e8>)
 8000578:	4293      	cmp	r3, r2
 800057a:	ddf8      	ble.n	800056e <main+0x3a6>
						GPIOD_ODR &= ~(1<<15);
 800057c:	4b0b      	ldr	r3, [pc, #44]	; (80005ac <main+0x3e4>)
 800057e:	681b      	ldr	r3, [r3, #0]
 8000580:	4a0a      	ldr	r2, [pc, #40]	; (80005ac <main+0x3e4>)
 8000582:	f423 4300 	bic.w	r3, r3, #32768	; 0x8000
 8000586:	6013      	str	r3, [r2, #0]
						for(i=0;i>=80000;i++);
 8000588:	2300      	movs	r3, #0
 800058a:	60fb      	str	r3, [r7, #12]
 800058c:	e002      	b.n	8000594 <main+0x3cc>
 800058e:	68fb      	ldr	r3, [r7, #12]
 8000590:	3301      	adds	r3, #1
 8000592:	60fb      	str	r3, [r7, #12]
 8000594:	68fb      	ldr	r3, [r7, #12]
 8000596:	4a06      	ldr	r2, [pc, #24]	; (80005b0 <main+0x3e8>)
 8000598:	4293      	cmp	r3, r2
 800059a:	dcf8      	bgt.n	800058e <main+0x3c6>
						for(j=0;j<5;j++)  //For LED BLUE
 800059c:	687b      	ldr	r3, [r7, #4]
 800059e:	3301      	adds	r3, #1
 80005a0:	607b      	str	r3, [r7, #4]
 80005a2:	687b      	ldr	r3, [r7, #4]
 80005a4:	2b04      	cmp	r3, #4
 80005a6:	ddd9      	ble.n	800055c <main+0x394>
					while((GPIOA_IDR & 0x01) == 1) // Switch Status On
 80005a8:	e64a      	b.n	8000240 <main+0x78>
 80005aa:	bf00      	nop
 80005ac:	40020c14 	.word	0x40020c14
 80005b0:	0001387f 	.word	0x0001387f

080005b4 <NMI_Handler>:
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
 80005b4:	b480      	push	{r7}
 80005b6:	af00      	add	r7, sp, #0
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */
  while (1)
 80005b8:	e7fe      	b.n	80005b8 <NMI_Handler+0x4>

080005ba <HardFault_Handler>:

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
 80005ba:	b480      	push	{r7}
 80005bc:	af00      	add	r7, sp, #0
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
 80005be:	e7fe      	b.n	80005be <HardFault_Handler+0x4>

080005c0 <MemManage_Handler>:

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
 80005c0:	b480      	push	{r7}
 80005c2:	af00      	add	r7, sp, #0
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
 80005c4:	e7fe      	b.n	80005c4 <MemManage_Handler+0x4>

080005c6 <BusFault_Handler>:

/**
  * @brief This function handles Pre-fetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
 80005c6:	b480      	push	{r7}
 80005c8:	af00      	add	r7, sp, #0
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
 80005ca:	e7fe      	b.n	80005ca <BusFault_Handler+0x4>

080005cc <UsageFault_Handler>:

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
 80005cc:	b480      	push	{r7}
 80005ce:	af00      	add	r7, sp, #0
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
 80005d0:	e7fe      	b.n	80005d0 <UsageFault_Handler+0x4>

080005d2 <SVC_Handler>:

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
 80005d2:	b480      	push	{r7}
 80005d4:	af00      	add	r7, sp, #0

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}
 80005d6:	bf00      	nop
 80005d8:	46bd      	mov	sp, r7
 80005da:	f85d 7b04 	ldr.w	r7, [sp], #4
 80005de:	4770      	bx	lr

080005e0 <DebugMon_Handler>:

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
 80005e0:	b480      	push	{r7}
 80005e2:	af00      	add	r7, sp, #0

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}
 80005e4:	bf00      	nop
 80005e6:	46bd      	mov	sp, r7
 80005e8:	f85d 7b04 	ldr.w	r7, [sp], #4
 80005ec:	4770      	bx	lr

080005ee <PendSV_Handler>:

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
 80005ee:	b480      	push	{r7}
 80005f0:	af00      	add	r7, sp, #0

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}
 80005f2:	bf00      	nop
 80005f4:	46bd      	mov	sp, r7
 80005f6:	f85d 7b04 	ldr.w	r7, [sp], #4
 80005fa:	4770      	bx	lr

080005fc <SysTick_Handler>:

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
 80005fc:	b580      	push	{r7, lr}
 80005fe:	af00      	add	r7, sp, #0
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
 8000600:	f000 f848 	bl	8000694 <HAL_IncTick>
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}
 8000604:	bf00      	nop
 8000606:	bd80      	pop	{r7, pc}

08000608 <OTG_FS_IRQHandler>:

/**
  * @brief This function handles USB On The Go FS global interrupt.
  */
void OTG_FS_IRQHandler(void)
{
 8000608:	b580      	push	{r7, lr}
 800060a:	af00      	add	r7, sp, #0
  /* USER CODE BEGIN OTG_FS_IRQn 0 */

  /* USER CODE END OTG_FS_IRQn 0 */
  HAL_HCD_IRQHandler(&hhcd_USB_OTG_FS);
 800060c:	4802      	ldr	r0, [pc, #8]	; (8000618 <OTG_FS_IRQHandler+0x10>)
 800060e:	f000 f855 	bl	80006bc <HAL_HCD_IRQHandler>
  /* USER CODE BEGIN OTG_FS_IRQn 1 */

  /* USER CODE END OTG_FS_IRQn 1 */
}
 8000612:	bf00      	nop
 8000614:	bd80      	pop	{r7, pc}
 8000616:	bf00      	nop
 8000618:	20000024 	.word	0x20000024

0800061c <SystemInit>:
  *         configuration.
  * @param  None
  * @retval None
  */
void SystemInit(void)
{
 800061c:	b480      	push	{r7}
 800061e:	af00      	add	r7, sp, #0
  /* FPU settings ------------------------------------------------------------*/
  #if (__FPU_PRESENT == 1) && (__FPU_USED == 1)
    SCB->CPACR |= ((3UL << 10*2)|(3UL << 11*2));  /* set CP10 and CP11 Full Access */
 8000620:	4b06      	ldr	r3, [pc, #24]	; (800063c <SystemInit+0x20>)
 8000622:	f8d3 3088 	ldr.w	r3, [r3, #136]	; 0x88
 8000626:	4a05      	ldr	r2, [pc, #20]	; (800063c <SystemInit+0x20>)
 8000628:	f443 0370 	orr.w	r3, r3, #15728640	; 0xf00000
 800062c:	f8c2 3088 	str.w	r3, [r2, #136]	; 0x88

  /* Configure the Vector Table location -------------------------------------*/
#if defined(USER_VECT_TAB_ADDRESS)
  SCB->VTOR = VECT_TAB_BASE_ADDRESS | VECT_TAB_OFFSET; /* Vector Table Relocation in Internal SRAM */
#endif /* USER_VECT_TAB_ADDRESS */
}
 8000630:	bf00      	nop
 8000632:	46bd      	mov	sp, r7
 8000634:	f85d 7b04 	ldr.w	r7, [sp], #4
 8000638:	4770      	bx	lr
 800063a:	bf00      	nop
 800063c:	e000ed00 	.word	0xe000ed00

08000640 <Reset_Handler>:

    .section  .text.Reset_Handler
  .weak  Reset_Handler
  .type  Reset_Handler, %function
Reset_Handler:  
  ldr   sp, =_estack     /* set stack pointer */
 8000640:	f8df d034 	ldr.w	sp, [pc, #52]	; 8000678 <LoopFillZerobss+0x12>

/* Copy the data segment initializers from flash to SRAM */  
  ldr r0, =_sdata
 8000644:	480d      	ldr	r0, [pc, #52]	; (800067c <LoopFillZerobss+0x16>)
  ldr r1, =_edata
 8000646:	490e      	ldr	r1, [pc, #56]	; (8000680 <LoopFillZerobss+0x1a>)
  ldr r2, =_sidata
 8000648:	4a0e      	ldr	r2, [pc, #56]	; (8000684 <LoopFillZerobss+0x1e>)
  movs r3, #0
 800064a:	2300      	movs	r3, #0
  b LoopCopyDataInit
 800064c:	e002      	b.n	8000654 <LoopCopyDataInit>

0800064e <CopyDataInit>:

CopyDataInit:
  ldr r4, [r2, r3]
 800064e:	58d4      	ldr	r4, [r2, r3]
  str r4, [r0, r3]
 8000650:	50c4      	str	r4, [r0, r3]
  adds r3, r3, #4
 8000652:	3304      	adds	r3, #4

08000654 <LoopCopyDataInit>:

LoopCopyDataInit:
  adds r4, r0, r3
 8000654:	18c4      	adds	r4, r0, r3
  cmp r4, r1
 8000656:	428c      	cmp	r4, r1
  bcc CopyDataInit
 8000658:	d3f9      	bcc.n	800064e <CopyDataInit>
  
/* Zero fill the bss segment. */
  ldr r2, =_sbss
 800065a:	4a0b      	ldr	r2, [pc, #44]	; (8000688 <LoopFillZerobss+0x22>)
  ldr r4, =_ebss
 800065c:	4c0b      	ldr	r4, [pc, #44]	; (800068c <LoopFillZerobss+0x26>)
  movs r3, #0
 800065e:	2300      	movs	r3, #0
  b LoopFillZerobss
 8000660:	e001      	b.n	8000666 <LoopFillZerobss>

08000662 <FillZerobss>:

FillZerobss:
  str  r3, [r2]
 8000662:	6013      	str	r3, [r2, #0]
  adds r2, r2, #4
 8000664:	3204      	adds	r2, #4

08000666 <LoopFillZerobss>:

LoopFillZerobss:
  cmp r2, r4
 8000666:	42a2      	cmp	r2, r4
  bcc FillZerobss
 8000668:	d3fb      	bcc.n	8000662 <FillZerobss>

/* Call the clock system initialization function.*/
  bl  SystemInit   
 800066a:	f7ff ffd7 	bl	800061c <SystemInit>
/* Call static constructors */
    bl __libc_init_array
 800066e:	f001 fd63 	bl	8002138 <__libc_init_array>
/* Call the application's entry point.*/
  bl  main
 8000672:	f7ff fda9 	bl	80001c8 <main>
  bx  lr    
 8000676:	4770      	bx	lr
  ldr   sp, =_estack     /* set stack pointer */
 8000678:	20020000 	.word	0x20020000
  ldr r0, =_sdata
 800067c:	20000000 	.word	0x20000000
  ldr r1, =_edata
 8000680:	20000004 	.word	0x20000004
  ldr r2, =_sidata
 8000684:	080021a0 	.word	0x080021a0
  ldr r2, =_sbss
 8000688:	20000004 	.word	0x20000004
  ldr r4, =_ebss
 800068c:	20000328 	.word	0x20000328

08000690 <ADC_IRQHandler>:
 * @retval None       
*/
    .section  .text.Default_Handler,"ax",%progbits
Default_Handler:
Infinite_Loop:
  b  Infinite_Loop
 8000690:	e7fe      	b.n	8000690 <ADC_IRQHandler>
	...

08000694 <HAL_IncTick>:
 * @note This function is declared as __weak to be overwritten in case of other 
  *      implementations in user file.
  * @retval None
  */
__weak void HAL_IncTick(void)
{
 8000694:	b480      	push	{r7}
 8000696:	af00      	add	r7, sp, #0
  uwTick += uwTickFreq;
 8000698:	4b06      	ldr	r3, [pc, #24]	; (80006b4 <HAL_IncTick+0x20>)
 800069a:	781b      	ldrb	r3, [r3, #0]
 800069c:	461a      	mov	r2, r3
 800069e:	4b06      	ldr	r3, [pc, #24]	; (80006b8 <HAL_IncTick+0x24>)
 80006a0:	681b      	ldr	r3, [r3, #0]
 80006a2:	4413      	add	r3, r2
 80006a4:	4a04      	ldr	r2, [pc, #16]	; (80006b8 <HAL_IncTick+0x24>)
 80006a6:	6013      	str	r3, [r2, #0]
}
 80006a8:	bf00      	nop
 80006aa:	46bd      	mov	sp, r7
 80006ac:	f85d 7b04 	ldr.w	r7, [sp], #4
 80006b0:	4770      	bx	lr
 80006b2:	bf00      	nop
 80006b4:	20000000 	.word	0x20000000
 80006b8:	20000020 	.word	0x20000020

080006bc <HAL_HCD_IRQHandler>:
  * @brief  Handle HCD interrupt request.
  * @param  hhcd HCD handle
  * @retval None
  */
void HAL_HCD_IRQHandler(HCD_HandleTypeDef *hhcd)
{
 80006bc:	b580      	push	{r7, lr}
 80006be:	b086      	sub	sp, #24
 80006c0:	af00      	add	r7, sp, #0
 80006c2:	6078      	str	r0, [r7, #4]
  USB_OTG_GlobalTypeDef *USBx = hhcd->Instance;
 80006c4:	687b      	ldr	r3, [r7, #4]
 80006c6:	681b      	ldr	r3, [r3, #0]
 80006c8:	613b      	str	r3, [r7, #16]
  uint32_t USBx_BASE = (uint32_t)USBx;
 80006ca:	693b      	ldr	r3, [r7, #16]
 80006cc:	60fb      	str	r3, [r7, #12]
  uint32_t i;
  uint32_t interrupt;

  /* Ensure that we are in device mode */
  if (USB_GetMode(hhcd->Instance) == USB_OTG_MODE_HOST)
 80006ce:	687b      	ldr	r3, [r7, #4]
 80006d0:	681b      	ldr	r3, [r3, #0]
 80006d2:	4618      	mov	r0, r3
 80006d4:	f001 fa0f 	bl	8001af6 <USB_GetMode>
 80006d8:	4603      	mov	r3, r0
 80006da:	2b01      	cmp	r3, #1
 80006dc:	f040 80f6 	bne.w	80008cc <HAL_HCD_IRQHandler+0x210>
  {
    /* Avoid spurious interrupt */
    if (__HAL_HCD_IS_INVALID_INTERRUPT(hhcd))
 80006e0:	687b      	ldr	r3, [r7, #4]
 80006e2:	681b      	ldr	r3, [r3, #0]
 80006e4:	4618      	mov	r0, r3
 80006e6:	f001 f9f3 	bl	8001ad0 <USB_ReadInterrupts>
 80006ea:	4603      	mov	r3, r0
 80006ec:	2b00      	cmp	r3, #0
 80006ee:	f000 80ec 	beq.w	80008ca <HAL_HCD_IRQHandler+0x20e>
    {
      return;
    }

    if (__HAL_HCD_GET_FLAG(hhcd, USB_OTG_GINTSTS_PXFR_INCOMPISOOUT))
 80006f2:	687b      	ldr	r3, [r7, #4]
 80006f4:	681b      	ldr	r3, [r3, #0]
 80006f6:	4618      	mov	r0, r3
 80006f8:	f001 f9ea 	bl	8001ad0 <USB_ReadInterrupts>
 80006fc:	4603      	mov	r3, r0
 80006fe:	f403 1300 	and.w	r3, r3, #2097152	; 0x200000
 8000702:	f5b3 1f00 	cmp.w	r3, #2097152	; 0x200000
 8000706:	d104      	bne.n	8000712 <HAL_HCD_IRQHandler+0x56>
    {
      /* Incorrect mode, acknowledge the interrupt */
      __HAL_HCD_CLEAR_FLAG(hhcd, USB_OTG_GINTSTS_PXFR_INCOMPISOOUT);
 8000708:	687b      	ldr	r3, [r7, #4]
 800070a:	681b      	ldr	r3, [r3, #0]
 800070c:	f44f 1200 	mov.w	r2, #2097152	; 0x200000
 8000710:	615a      	str	r2, [r3, #20]
    }

    if (__HAL_HCD_GET_FLAG(hhcd, USB_OTG_GINTSTS_IISOIXFR))
 8000712:	687b      	ldr	r3, [r7, #4]
 8000714:	681b      	ldr	r3, [r3, #0]
 8000716:	4618      	mov	r0, r3
 8000718:	f001 f9da 	bl	8001ad0 <USB_ReadInterrupts>
 800071c:	4603      	mov	r3, r0
 800071e:	f403 1380 	and.w	r3, r3, #1048576	; 0x100000
 8000722:	f5b3 1f80 	cmp.w	r3, #1048576	; 0x100000
 8000726:	d104      	bne.n	8000732 <HAL_HCD_IRQHandler+0x76>
    {
      /* Incorrect mode, acknowledge the interrupt */
      __HAL_HCD_CLEAR_FLAG(hhcd, USB_OTG_GINTSTS_IISOIXFR);
 8000728:	687b      	ldr	r3, [r7, #4]
 800072a:	681b      	ldr	r3, [r3, #0]
 800072c:	f44f 1280 	mov.w	r2, #1048576	; 0x100000
 8000730:	615a      	str	r2, [r3, #20]
    }

    if (__HAL_HCD_GET_FLAG(hhcd, USB_OTG_GINTSTS_PTXFE))
 8000732:	687b      	ldr	r3, [r7, #4]
 8000734:	681b      	ldr	r3, [r3, #0]
 8000736:	4618      	mov	r0, r3
 8000738:	f001 f9ca 	bl	8001ad0 <USB_ReadInterrupts>
 800073c:	4603      	mov	r3, r0
 800073e:	f003 6380 	and.w	r3, r3, #67108864	; 0x4000000
 8000742:	f1b3 6f80 	cmp.w	r3, #67108864	; 0x4000000
 8000746:	d104      	bne.n	8000752 <HAL_HCD_IRQHandler+0x96>
    {
      /* Incorrect mode, acknowledge the interrupt */
      __HAL_HCD_CLEAR_FLAG(hhcd, USB_OTG_GINTSTS_PTXFE);
 8000748:	687b      	ldr	r3, [r7, #4]
 800074a:	681b      	ldr	r3, [r3, #0]
 800074c:	f04f 6280 	mov.w	r2, #67108864	; 0x4000000
 8000750:	615a      	str	r2, [r3, #20]
    }

    if (__HAL_HCD_GET_FLAG(hhcd, USB_OTG_GINTSTS_MMIS))
 8000752:	687b      	ldr	r3, [r7, #4]
 8000754:	681b      	ldr	r3, [r3, #0]
 8000756:	4618      	mov	r0, r3
 8000758:	f001 f9ba 	bl	8001ad0 <USB_ReadInterrupts>
 800075c:	4603      	mov	r3, r0
 800075e:	f003 0302 	and.w	r3, r3, #2
 8000762:	2b02      	cmp	r3, #2
 8000764:	d103      	bne.n	800076e <HAL_HCD_IRQHandler+0xb2>
    {
      /* Incorrect mode, acknowledge the interrupt */
      __HAL_HCD_CLEAR_FLAG(hhcd, USB_OTG_GINTSTS_MMIS);
 8000766:	687b      	ldr	r3, [r7, #4]
 8000768:	681b      	ldr	r3, [r3, #0]
 800076a:	2202      	movs	r2, #2
 800076c:	615a      	str	r2, [r3, #20]
    }

    /* Handle Host Disconnect Interrupts */
    if (__HAL_HCD_GET_FLAG(hhcd, USB_OTG_GINTSTS_DISCINT))
 800076e:	687b      	ldr	r3, [r7, #4]
 8000770:	681b      	ldr	r3, [r3, #0]
 8000772:	4618      	mov	r0, r3
 8000774:	f001 f9ac 	bl	8001ad0 <USB_ReadInterrupts>
 8000778:	4603      	mov	r3, r0
 800077a:	f003 5300 	and.w	r3, r3, #536870912	; 0x20000000
 800077e:	f1b3 5f00 	cmp.w	r3, #536870912	; 0x20000000
 8000782:	d11c      	bne.n	80007be <HAL_HCD_IRQHandler+0x102>
    {
      __HAL_HCD_CLEAR_FLAG(hhcd, USB_OTG_GINTSTS_DISCINT);
 8000784:	687b      	ldr	r3, [r7, #4]
 8000786:	681b      	ldr	r3, [r3, #0]
 8000788:	f04f 5200 	mov.w	r2, #536870912	; 0x20000000
 800078c:	615a      	str	r2, [r3, #20]

      if ((USBx_HPRT0 & USB_OTG_HPRT_PCSTS) == 0U)
 800078e:	68fb      	ldr	r3, [r7, #12]
 8000790:	f503 6388 	add.w	r3, r3, #1088	; 0x440
 8000794:	681b      	ldr	r3, [r3, #0]
 8000796:	f003 0301 	and.w	r3, r3, #1
 800079a:	2b00      	cmp	r3, #0
 800079c:	d10f      	bne.n	80007be <HAL_HCD_IRQHandler+0x102>
      {
        /* Flush USB Fifo */
        (void)USB_FlushTxFifo(USBx, 0x10U);
 800079e:	2110      	movs	r1, #16
 80007a0:	6938      	ldr	r0, [r7, #16]
 80007a2:	f001 f8d9 	bl	8001958 <USB_FlushTxFifo>
        (void)USB_FlushRxFifo(USBx);
 80007a6:	6938      	ldr	r0, [r7, #16]
 80007a8:	f001 f90a 	bl	80019c0 <USB_FlushRxFifo>

        /* Restore FS Clock */
        (void)USB_InitFSLSPClkSel(hhcd->Instance, HCFG_48_MHZ);
 80007ac:	687b      	ldr	r3, [r7, #4]
 80007ae:	681b      	ldr	r3, [r3, #0]
 80007b0:	2101      	movs	r1, #1
 80007b2:	4618      	mov	r0, r3
 80007b4:	f001 f9ad 	bl	8001b12 <USB_InitFSLSPClkSel>

        /* Handle Host Port Disconnect Interrupt */
#if (USE_HAL_HCD_REGISTER_CALLBACKS == 1U)
        hhcd->DisconnectCallback(hhcd);
#else
        HAL_HCD_Disconnect_Callback(hhcd);
 80007b8:	6878      	ldr	r0, [r7, #4]
 80007ba:	f001 fc3e 	bl	800203a <HAL_HCD_Disconnect_Callback>
#endif /* USE_HAL_HCD_REGISTER_CALLBACKS */
      }
    }

    /* Handle Host Port Interrupts */
    if (__HAL_HCD_GET_FLAG(hhcd, USB_OTG_GINTSTS_HPRTINT))
 80007be:	687b      	ldr	r3, [r7, #4]
 80007c0:	681b      	ldr	r3, [r3, #0]
 80007c2:	4618      	mov	r0, r3
 80007c4:	f001 f984 	bl	8001ad0 <USB_ReadInterrupts>
 80007c8:	4603      	mov	r3, r0
 80007ca:	f003 7380 	and.w	r3, r3, #16777216	; 0x1000000
 80007ce:	f1b3 7f80 	cmp.w	r3, #16777216	; 0x1000000
 80007d2:	d102      	bne.n	80007da <HAL_HCD_IRQHandler+0x11e>
    {
      HCD_Port_IRQHandler(hhcd);
 80007d4:	6878      	ldr	r0, [r7, #4]
 80007d6:	f001 f829 	bl	800182c <HCD_Port_IRQHandler>
    }

    /* Handle Host SOF Interrupt */
    if (__HAL_HCD_GET_FLAG(hhcd, USB_OTG_GINTSTS_SOF))
 80007da:	687b      	ldr	r3, [r7, #4]
 80007dc:	681b      	ldr	r3, [r3, #0]
 80007de:	4618      	mov	r0, r3
 80007e0:	f001 f976 	bl	8001ad0 <USB_ReadInterrupts>
 80007e4:	4603      	mov	r3, r0
 80007e6:	f003 0308 	and.w	r3, r3, #8
 80007ea:	2b08      	cmp	r3, #8
 80007ec:	d106      	bne.n	80007fc <HAL_HCD_IRQHandler+0x140>
    {
#if (USE_HAL_HCD_REGISTER_CALLBACKS == 1U)
      hhcd->SOFCallback(hhcd);
#else
      HAL_HCD_SOF_Callback(hhcd);
 80007ee:	6878      	ldr	r0, [r7, #4]
 80007f0:	f001 fc07 	bl	8002002 <HAL_HCD_SOF_Callback>
#endif /* USE_HAL_HCD_REGISTER_CALLBACKS */

      __HAL_HCD_CLEAR_FLAG(hhcd, USB_OTG_GINTSTS_SOF);
 80007f4:	687b      	ldr	r3, [r7, #4]
 80007f6:	681b      	ldr	r3, [r3, #0]
 80007f8:	2208      	movs	r2, #8
 80007fa:	615a      	str	r2, [r3, #20]
    }

    /* Handle Rx Queue Level Interrupts */
    if ((__HAL_HCD_GET_FLAG(hhcd, USB_OTG_GINTSTS_RXFLVL)) != 0U)
 80007fc:	687b      	ldr	r3, [r7, #4]
 80007fe:	681b      	ldr	r3, [r3, #0]
 8000800:	4618      	mov	r0, r3
 8000802:	f001 f965 	bl	8001ad0 <USB_ReadInterrupts>
 8000806:	4603      	mov	r3, r0
 8000808:	f003 0310 	and.w	r3, r3, #16
 800080c:	2b10      	cmp	r3, #16
 800080e:	d101      	bne.n	8000814 <HAL_HCD_IRQHandler+0x158>
 8000810:	2301      	movs	r3, #1
 8000812:	e000      	b.n	8000816 <HAL_HCD_IRQHandler+0x15a>
 8000814:	2300      	movs	r3, #0
 8000816:	2b00      	cmp	r3, #0
 8000818:	d012      	beq.n	8000840 <HAL_HCD_IRQHandler+0x184>
    {
      USB_MASK_INTERRUPT(hhcd->Instance, USB_OTG_GINTSTS_RXFLVL);
 800081a:	687b      	ldr	r3, [r7, #4]
 800081c:	681b      	ldr	r3, [r3, #0]
 800081e:	699a      	ldr	r2, [r3, #24]
 8000820:	687b      	ldr	r3, [r7, #4]
 8000822:	681b      	ldr	r3, [r3, #0]
 8000824:	f022 0210 	bic.w	r2, r2, #16
 8000828:	619a      	str	r2, [r3, #24]

      HCD_RXQLVL_IRQHandler(hhcd);
 800082a:	6878      	ldr	r0, [r7, #4]
 800082c:	f000 ff2c 	bl	8001688 <HCD_RXQLVL_IRQHandler>

      USB_UNMASK_INTERRUPT(hhcd->Instance, USB_OTG_GINTSTS_RXFLVL);
 8000830:	687b      	ldr	r3, [r7, #4]
 8000832:	681b      	ldr	r3, [r3, #0]
 8000834:	699a      	ldr	r2, [r3, #24]
 8000836:	687b      	ldr	r3, [r7, #4]
 8000838:	681b      	ldr	r3, [r3, #0]
 800083a:	f042 0210 	orr.w	r2, r2, #16
 800083e:	619a      	str	r2, [r3, #24]
    }

    /* Handle Host channel Interrupt */
    if (__HAL_HCD_GET_FLAG(hhcd, USB_OTG_GINTSTS_HCINT))
 8000840:	687b      	ldr	r3, [r7, #4]
 8000842:	681b      	ldr	r3, [r3, #0]
 8000844:	4618      	mov	r0, r3
 8000846:	f001 f943 	bl	8001ad0 <USB_ReadInterrupts>
 800084a:	4603      	mov	r3, r0
 800084c:	f003 7300 	and.w	r3, r3, #33554432	; 0x2000000
 8000850:	f1b3 7f00 	cmp.w	r3, #33554432	; 0x2000000
 8000854:	d13a      	bne.n	80008cc <HAL_HCD_IRQHandler+0x210>
    {
      interrupt = USB_HC_ReadInterrupt(hhcd->Instance);
 8000856:	687b      	ldr	r3, [r7, #4]
 8000858:	681b      	ldr	r3, [r3, #0]
 800085a:	4618      	mov	r0, r3
 800085c:	f001 f993 	bl	8001b86 <USB_HC_ReadInterrupt>
 8000860:	60b8      	str	r0, [r7, #8]
      for (i = 0U; i < hhcd->Init.Host_channels; i++)
 8000862:	2300      	movs	r3, #0
 8000864:	617b      	str	r3, [r7, #20]
 8000866:	e025      	b.n	80008b4 <HAL_HCD_IRQHandler+0x1f8>
      {
        if ((interrupt & (1UL << (i & 0xFU))) != 0U)
 8000868:	697b      	ldr	r3, [r7, #20]
 800086a:	f003 030f 	and.w	r3, r3, #15
 800086e:	68ba      	ldr	r2, [r7, #8]
 8000870:	fa22 f303 	lsr.w	r3, r2, r3
 8000874:	f003 0301 	and.w	r3, r3, #1
 8000878:	2b00      	cmp	r3, #0
 800087a:	d018      	beq.n	80008ae <HAL_HCD_IRQHandler+0x1f2>
        {
          if ((USBx_HC(i)->HCCHAR & USB_OTG_HCCHAR_EPDIR) == USB_OTG_HCCHAR_EPDIR)
 800087c:	697b      	ldr	r3, [r7, #20]
 800087e:	015a      	lsls	r2, r3, #5
 8000880:	68fb      	ldr	r3, [r7, #12]
 8000882:	4413      	add	r3, r2
 8000884:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 8000888:	681b      	ldr	r3, [r3, #0]
 800088a:	f403 4300 	and.w	r3, r3, #32768	; 0x8000
 800088e:	f5b3 4f00 	cmp.w	r3, #32768	; 0x8000
 8000892:	d106      	bne.n	80008a2 <HAL_HCD_IRQHandler+0x1e6>
          {
            HCD_HC_IN_IRQHandler(hhcd, (uint8_t)i);
 8000894:	697b      	ldr	r3, [r7, #20]
 8000896:	b2db      	uxtb	r3, r3
 8000898:	4619      	mov	r1, r3
 800089a:	6878      	ldr	r0, [r7, #4]
 800089c:	f000 f836 	bl	800090c <HCD_HC_IN_IRQHandler>
 80008a0:	e005      	b.n	80008ae <HAL_HCD_IRQHandler+0x1f2>
          }
          else
          {
            HCD_HC_OUT_IRQHandler(hhcd, (uint8_t)i);
 80008a2:	697b      	ldr	r3, [r7, #20]
 80008a4:	b2db      	uxtb	r3, r3
 80008a6:	4619      	mov	r1, r3
 80008a8:	6878      	ldr	r0, [r7, #4]
 80008aa:	f000 fb84 	bl	8000fb6 <HCD_HC_OUT_IRQHandler>
      for (i = 0U; i < hhcd->Init.Host_channels; i++)
 80008ae:	697b      	ldr	r3, [r7, #20]
 80008b0:	3301      	adds	r3, #1
 80008b2:	617b      	str	r3, [r7, #20]
 80008b4:	687b      	ldr	r3, [r7, #4]
 80008b6:	689b      	ldr	r3, [r3, #8]
 80008b8:	697a      	ldr	r2, [r7, #20]
 80008ba:	429a      	cmp	r2, r3
 80008bc:	d3d4      	bcc.n	8000868 <HAL_HCD_IRQHandler+0x1ac>
          }
        }
      }
      __HAL_HCD_CLEAR_FLAG(hhcd, USB_OTG_GINTSTS_HCINT);
 80008be:	687b      	ldr	r3, [r7, #4]
 80008c0:	681b      	ldr	r3, [r3, #0]
 80008c2:	f04f 7200 	mov.w	r2, #33554432	; 0x2000000
 80008c6:	615a      	str	r2, [r3, #20]
 80008c8:	e000      	b.n	80008cc <HAL_HCD_IRQHandler+0x210>
      return;
 80008ca:	bf00      	nop
    }
  }
}
 80008cc:	3718      	adds	r7, #24
 80008ce:	46bd      	mov	sp, r7
 80008d0:	bd80      	pop	{r7, pc}

080008d2 <HAL_HCD_Stop>:
  * @param  hhcd HCD handle
  * @retval HAL status
  */

HAL_StatusTypeDef HAL_HCD_Stop(HCD_HandleTypeDef *hhcd)
{
 80008d2:	b580      	push	{r7, lr}
 80008d4:	b082      	sub	sp, #8
 80008d6:	af00      	add	r7, sp, #0
 80008d8:	6078      	str	r0, [r7, #4]
  __HAL_LOCK(hhcd);
 80008da:	687b      	ldr	r3, [r7, #4]
 80008dc:	f893 32f8 	ldrb.w	r3, [r3, #760]	; 0x2f8
 80008e0:	2b01      	cmp	r3, #1
 80008e2:	d101      	bne.n	80008e8 <HAL_HCD_Stop+0x16>
 80008e4:	2302      	movs	r3, #2
 80008e6:	e00d      	b.n	8000904 <HAL_HCD_Stop+0x32>
 80008e8:	687b      	ldr	r3, [r7, #4]
 80008ea:	2201      	movs	r2, #1
 80008ec:	f883 22f8 	strb.w	r2, [r3, #760]	; 0x2f8
  (void)USB_StopHost(hhcd->Instance);
 80008f0:	687b      	ldr	r3, [r7, #4]
 80008f2:	681b      	ldr	r3, [r3, #0]
 80008f4:	4618      	mov	r0, r3
 80008f6:	f001 fa53 	bl	8001da0 <USB_StopHost>
  __HAL_UNLOCK(hhcd);
 80008fa:	687b      	ldr	r3, [r7, #4]
 80008fc:	2200      	movs	r2, #0
 80008fe:	f883 22f8 	strb.w	r2, [r3, #760]	; 0x2f8

  return HAL_OK;
 8000902:	2300      	movs	r3, #0
}
 8000904:	4618      	mov	r0, r3
 8000906:	3708      	adds	r7, #8
 8000908:	46bd      	mov	sp, r7
 800090a:	bd80      	pop	{r7, pc}

0800090c <HCD_HC_IN_IRQHandler>:
  * @param  chnum Channel number.
  *         This parameter can be a value from 1 to 15
  * @retval none
  */
static void HCD_HC_IN_IRQHandler(HCD_HandleTypeDef *hhcd, uint8_t chnum)
{
 800090c:	b580      	push	{r7, lr}
 800090e:	b086      	sub	sp, #24
 8000910:	af00      	add	r7, sp, #0
 8000912:	6078      	str	r0, [r7, #4]
 8000914:	460b      	mov	r3, r1
 8000916:	70fb      	strb	r3, [r7, #3]
  USB_OTG_GlobalTypeDef *USBx = hhcd->Instance;
 8000918:	687b      	ldr	r3, [r7, #4]
 800091a:	681b      	ldr	r3, [r3, #0]
 800091c:	617b      	str	r3, [r7, #20]
  uint32_t USBx_BASE = (uint32_t)USBx;
 800091e:	697b      	ldr	r3, [r7, #20]
 8000920:	613b      	str	r3, [r7, #16]
  uint32_t ch_num = (uint32_t)chnum;
 8000922:	78fb      	ldrb	r3, [r7, #3]
 8000924:	60fb      	str	r3, [r7, #12]

  uint32_t tmpreg;

  if ((USBx_HC(ch_num)->HCINT & USB_OTG_HCINT_AHBERR) == USB_OTG_HCINT_AHBERR)
 8000926:	68fb      	ldr	r3, [r7, #12]
 8000928:	015a      	lsls	r2, r3, #5
 800092a:	693b      	ldr	r3, [r7, #16]
 800092c:	4413      	add	r3, r2
 800092e:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 8000932:	689b      	ldr	r3, [r3, #8]
 8000934:	f003 0304 	and.w	r3, r3, #4
 8000938:	2b04      	cmp	r3, #4
 800093a:	d11a      	bne.n	8000972 <HCD_HC_IN_IRQHandler+0x66>
  {
    __HAL_HCD_CLEAR_HC_INT(ch_num, USB_OTG_HCINT_AHBERR);
 800093c:	68fb      	ldr	r3, [r7, #12]
 800093e:	015a      	lsls	r2, r3, #5
 8000940:	693b      	ldr	r3, [r7, #16]
 8000942:	4413      	add	r3, r2
 8000944:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 8000948:	461a      	mov	r2, r3
 800094a:	2304      	movs	r3, #4
 800094c:	6093      	str	r3, [r2, #8]
    hhcd->hc[ch_num].state = HC_XACTERR;
 800094e:	687a      	ldr	r2, [r7, #4]
 8000950:	68fb      	ldr	r3, [r7, #12]
 8000952:	212c      	movs	r1, #44	; 0x2c
 8000954:	fb01 f303 	mul.w	r3, r1, r3
 8000958:	4413      	add	r3, r2
 800095a:	3361      	adds	r3, #97	; 0x61
 800095c:	2206      	movs	r2, #6
 800095e:	701a      	strb	r2, [r3, #0]
    (void)USB_HC_Halt(hhcd->Instance, (uint8_t)ch_num);
 8000960:	687b      	ldr	r3, [r7, #4]
 8000962:	681b      	ldr	r3, [r3, #0]
 8000964:	68fa      	ldr	r2, [r7, #12]
 8000966:	b2d2      	uxtb	r2, r2
 8000968:	4611      	mov	r1, r2
 800096a:	4618      	mov	r0, r3
 800096c:	f001 f91c 	bl	8001ba8 <USB_HC_Halt>
 8000970:	e0af      	b.n	8000ad2 <HCD_HC_IN_IRQHandler+0x1c6>
  }
  else if ((USBx_HC(ch_num)->HCINT & USB_OTG_HCINT_BBERR) == USB_OTG_HCINT_BBERR)
 8000972:	68fb      	ldr	r3, [r7, #12]
 8000974:	015a      	lsls	r2, r3, #5
 8000976:	693b      	ldr	r3, [r7, #16]
 8000978:	4413      	add	r3, r2
 800097a:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 800097e:	689b      	ldr	r3, [r3, #8]
 8000980:	f403 7380 	and.w	r3, r3, #256	; 0x100
 8000984:	f5b3 7f80 	cmp.w	r3, #256	; 0x100
 8000988:	d11b      	bne.n	80009c2 <HCD_HC_IN_IRQHandler+0xb6>
  {
    __HAL_HCD_CLEAR_HC_INT(ch_num, USB_OTG_HCINT_BBERR);
 800098a:	68fb      	ldr	r3, [r7, #12]
 800098c:	015a      	lsls	r2, r3, #5
 800098e:	693b      	ldr	r3, [r7, #16]
 8000990:	4413      	add	r3, r2
 8000992:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 8000996:	461a      	mov	r2, r3
 8000998:	f44f 7380 	mov.w	r3, #256	; 0x100
 800099c:	6093      	str	r3, [r2, #8]
    hhcd->hc[ch_num].state = HC_BBLERR;
 800099e:	687a      	ldr	r2, [r7, #4]
 80009a0:	68fb      	ldr	r3, [r7, #12]
 80009a2:	212c      	movs	r1, #44	; 0x2c
 80009a4:	fb01 f303 	mul.w	r3, r1, r3
 80009a8:	4413      	add	r3, r2
 80009aa:	3361      	adds	r3, #97	; 0x61
 80009ac:	2207      	movs	r2, #7
 80009ae:	701a      	strb	r2, [r3, #0]
    (void)USB_HC_Halt(hhcd->Instance, (uint8_t)ch_num);
 80009b0:	687b      	ldr	r3, [r7, #4]
 80009b2:	681b      	ldr	r3, [r3, #0]
 80009b4:	68fa      	ldr	r2, [r7, #12]
 80009b6:	b2d2      	uxtb	r2, r2
 80009b8:	4611      	mov	r1, r2
 80009ba:	4618      	mov	r0, r3
 80009bc:	f001 f8f4 	bl	8001ba8 <USB_HC_Halt>
 80009c0:	e087      	b.n	8000ad2 <HCD_HC_IN_IRQHandler+0x1c6>
  }
  else if ((USBx_HC(ch_num)->HCINT & USB_OTG_HCINT_ACK) == USB_OTG_HCINT_ACK)
 80009c2:	68fb      	ldr	r3, [r7, #12]
 80009c4:	015a      	lsls	r2, r3, #5
 80009c6:	693b      	ldr	r3, [r7, #16]
 80009c8:	4413      	add	r3, r2
 80009ca:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 80009ce:	689b      	ldr	r3, [r3, #8]
 80009d0:	f003 0320 	and.w	r3, r3, #32
 80009d4:	2b20      	cmp	r3, #32
 80009d6:	d109      	bne.n	80009ec <HCD_HC_IN_IRQHandler+0xe0>
  {
    __HAL_HCD_CLEAR_HC_INT(ch_num, USB_OTG_HCINT_ACK);
 80009d8:	68fb      	ldr	r3, [r7, #12]
 80009da:	015a      	lsls	r2, r3, #5
 80009dc:	693b      	ldr	r3, [r7, #16]
 80009de:	4413      	add	r3, r2
 80009e0:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 80009e4:	461a      	mov	r2, r3
 80009e6:	2320      	movs	r3, #32
 80009e8:	6093      	str	r3, [r2, #8]
 80009ea:	e072      	b.n	8000ad2 <HCD_HC_IN_IRQHandler+0x1c6>
  }
  else if ((USBx_HC(ch_num)->HCINT & USB_OTG_HCINT_STALL) == USB_OTG_HCINT_STALL)
 80009ec:	68fb      	ldr	r3, [r7, #12]
 80009ee:	015a      	lsls	r2, r3, #5
 80009f0:	693b      	ldr	r3, [r7, #16]
 80009f2:	4413      	add	r3, r2
 80009f4:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 80009f8:	689b      	ldr	r3, [r3, #8]
 80009fa:	f003 0308 	and.w	r3, r3, #8
 80009fe:	2b08      	cmp	r3, #8
 8000a00:	d11a      	bne.n	8000a38 <HCD_HC_IN_IRQHandler+0x12c>
  {
    __HAL_HCD_CLEAR_HC_INT(ch_num, USB_OTG_HCINT_STALL);
 8000a02:	68fb      	ldr	r3, [r7, #12]
 8000a04:	015a      	lsls	r2, r3, #5
 8000a06:	693b      	ldr	r3, [r7, #16]
 8000a08:	4413      	add	r3, r2
 8000a0a:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 8000a0e:	461a      	mov	r2, r3
 8000a10:	2308      	movs	r3, #8
 8000a12:	6093      	str	r3, [r2, #8]
    hhcd->hc[ch_num].state = HC_STALL;
 8000a14:	687a      	ldr	r2, [r7, #4]
 8000a16:	68fb      	ldr	r3, [r7, #12]
 8000a18:	212c      	movs	r1, #44	; 0x2c
 8000a1a:	fb01 f303 	mul.w	r3, r1, r3
 8000a1e:	4413      	add	r3, r2
 8000a20:	3361      	adds	r3, #97	; 0x61
 8000a22:	2205      	movs	r2, #5
 8000a24:	701a      	strb	r2, [r3, #0]
    (void)USB_HC_Halt(hhcd->Instance, (uint8_t)ch_num);
 8000a26:	687b      	ldr	r3, [r7, #4]
 8000a28:	681b      	ldr	r3, [r3, #0]
 8000a2a:	68fa      	ldr	r2, [r7, #12]
 8000a2c:	b2d2      	uxtb	r2, r2
 8000a2e:	4611      	mov	r1, r2
 8000a30:	4618      	mov	r0, r3
 8000a32:	f001 f8b9 	bl	8001ba8 <USB_HC_Halt>
 8000a36:	e04c      	b.n	8000ad2 <HCD_HC_IN_IRQHandler+0x1c6>
  }
  else if ((USBx_HC(ch_num)->HCINT & USB_OTG_HCINT_DTERR) == USB_OTG_HCINT_DTERR)
 8000a38:	68fb      	ldr	r3, [r7, #12]
 8000a3a:	015a      	lsls	r2, r3, #5
 8000a3c:	693b      	ldr	r3, [r7, #16]
 8000a3e:	4413      	add	r3, r2
 8000a40:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 8000a44:	689b      	ldr	r3, [r3, #8]
 8000a46:	f403 6380 	and.w	r3, r3, #1024	; 0x400
 8000a4a:	f5b3 6f80 	cmp.w	r3, #1024	; 0x400
 8000a4e:	d11b      	bne.n	8000a88 <HCD_HC_IN_IRQHandler+0x17c>
  {
    __HAL_HCD_CLEAR_HC_INT(ch_num, USB_OTG_HCINT_DTERR);
 8000a50:	68fb      	ldr	r3, [r7, #12]
 8000a52:	015a      	lsls	r2, r3, #5
 8000a54:	693b      	ldr	r3, [r7, #16]
 8000a56:	4413      	add	r3, r2
 8000a58:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 8000a5c:	461a      	mov	r2, r3
 8000a5e:	f44f 6380 	mov.w	r3, #1024	; 0x400
 8000a62:	6093      	str	r3, [r2, #8]
    hhcd->hc[ch_num].state = HC_DATATGLERR;
 8000a64:	687a      	ldr	r2, [r7, #4]
 8000a66:	68fb      	ldr	r3, [r7, #12]
 8000a68:	212c      	movs	r1, #44	; 0x2c
 8000a6a:	fb01 f303 	mul.w	r3, r1, r3
 8000a6e:	4413      	add	r3, r2
 8000a70:	3361      	adds	r3, #97	; 0x61
 8000a72:	2208      	movs	r2, #8
 8000a74:	701a      	strb	r2, [r3, #0]
    (void)USB_HC_Halt(hhcd->Instance, (uint8_t)ch_num);
 8000a76:	687b      	ldr	r3, [r7, #4]
 8000a78:	681b      	ldr	r3, [r3, #0]
 8000a7a:	68fa      	ldr	r2, [r7, #12]
 8000a7c:	b2d2      	uxtb	r2, r2
 8000a7e:	4611      	mov	r1, r2
 8000a80:	4618      	mov	r0, r3
 8000a82:	f001 f891 	bl	8001ba8 <USB_HC_Halt>
 8000a86:	e024      	b.n	8000ad2 <HCD_HC_IN_IRQHandler+0x1c6>
  }
  else if ((USBx_HC(ch_num)->HCINT & USB_OTG_HCINT_TXERR) == USB_OTG_HCINT_TXERR)
 8000a88:	68fb      	ldr	r3, [r7, #12]
 8000a8a:	015a      	lsls	r2, r3, #5
 8000a8c:	693b      	ldr	r3, [r7, #16]
 8000a8e:	4413      	add	r3, r2
 8000a90:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 8000a94:	689b      	ldr	r3, [r3, #8]
 8000a96:	f003 0380 	and.w	r3, r3, #128	; 0x80
 8000a9a:	2b80      	cmp	r3, #128	; 0x80
 8000a9c:	d119      	bne.n	8000ad2 <HCD_HC_IN_IRQHandler+0x1c6>
  {
    __HAL_HCD_CLEAR_HC_INT(ch_num, USB_OTG_HCINT_TXERR);
 8000a9e:	68fb      	ldr	r3, [r7, #12]
 8000aa0:	015a      	lsls	r2, r3, #5
 8000aa2:	693b      	ldr	r3, [r7, #16]
 8000aa4:	4413      	add	r3, r2
 8000aa6:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 8000aaa:	461a      	mov	r2, r3
 8000aac:	2380      	movs	r3, #128	; 0x80
 8000aae:	6093      	str	r3, [r2, #8]
    hhcd->hc[ch_num].state = HC_XACTERR;
 8000ab0:	687a      	ldr	r2, [r7, #4]
 8000ab2:	68fb      	ldr	r3, [r7, #12]
 8000ab4:	212c      	movs	r1, #44	; 0x2c
 8000ab6:	fb01 f303 	mul.w	r3, r1, r3
 8000aba:	4413      	add	r3, r2
 8000abc:	3361      	adds	r3, #97	; 0x61
 8000abe:	2206      	movs	r2, #6
 8000ac0:	701a      	strb	r2, [r3, #0]
    (void)USB_HC_Halt(hhcd->Instance, (uint8_t)ch_num);
 8000ac2:	687b      	ldr	r3, [r7, #4]
 8000ac4:	681b      	ldr	r3, [r3, #0]
 8000ac6:	68fa      	ldr	r2, [r7, #12]
 8000ac8:	b2d2      	uxtb	r2, r2
 8000aca:	4611      	mov	r1, r2
 8000acc:	4618      	mov	r0, r3
 8000ace:	f001 f86b 	bl	8001ba8 <USB_HC_Halt>
  else
  {
    /* ... */
  }

  if ((USBx_HC(ch_num)->HCINT & USB_OTG_HCINT_FRMOR) == USB_OTG_HCINT_FRMOR)
 8000ad2:	68fb      	ldr	r3, [r7, #12]
 8000ad4:	015a      	lsls	r2, r3, #5
 8000ad6:	693b      	ldr	r3, [r7, #16]
 8000ad8:	4413      	add	r3, r2
 8000ada:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 8000ade:	689b      	ldr	r3, [r3, #8]
 8000ae0:	f403 7300 	and.w	r3, r3, #512	; 0x200
 8000ae4:	f5b3 7f00 	cmp.w	r3, #512	; 0x200
 8000ae8:	d112      	bne.n	8000b10 <HCD_HC_IN_IRQHandler+0x204>
  {
    (void)USB_HC_Halt(hhcd->Instance, (uint8_t)ch_num);
 8000aea:	687b      	ldr	r3, [r7, #4]
 8000aec:	681b      	ldr	r3, [r3, #0]
 8000aee:	68fa      	ldr	r2, [r7, #12]
 8000af0:	b2d2      	uxtb	r2, r2
 8000af2:	4611      	mov	r1, r2
 8000af4:	4618      	mov	r0, r3
 8000af6:	f001 f857 	bl	8001ba8 <USB_HC_Halt>
    __HAL_HCD_CLEAR_HC_INT(ch_num, USB_OTG_HCINT_FRMOR);
 8000afa:	68fb      	ldr	r3, [r7, #12]
 8000afc:	015a      	lsls	r2, r3, #5
 8000afe:	693b      	ldr	r3, [r7, #16]
 8000b00:	4413      	add	r3, r2
 8000b02:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 8000b06:	461a      	mov	r2, r3
 8000b08:	f44f 7300 	mov.w	r3, #512	; 0x200
 8000b0c:	6093      	str	r3, [r2, #8]
  }
  else
  {
    /* ... */
  }
}
 8000b0e:	e24e      	b.n	8000fae <HCD_HC_IN_IRQHandler+0x6a2>
  else if ((USBx_HC(ch_num)->HCINT & USB_OTG_HCINT_XFRC) == USB_OTG_HCINT_XFRC)
 8000b10:	68fb      	ldr	r3, [r7, #12]
 8000b12:	015a      	lsls	r2, r3, #5
 8000b14:	693b      	ldr	r3, [r7, #16]
 8000b16:	4413      	add	r3, r2
 8000b18:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 8000b1c:	689b      	ldr	r3, [r3, #8]
 8000b1e:	f003 0301 	and.w	r3, r3, #1
 8000b22:	2b01      	cmp	r3, #1
 8000b24:	f040 80df 	bne.w	8000ce6 <HCD_HC_IN_IRQHandler+0x3da>
    if (hhcd->Init.dma_enable != 0U)
 8000b28:	687b      	ldr	r3, [r7, #4]
 8000b2a:	691b      	ldr	r3, [r3, #16]
 8000b2c:	2b00      	cmp	r3, #0
 8000b2e:	d019      	beq.n	8000b64 <HCD_HC_IN_IRQHandler+0x258>
      hhcd->hc[ch_num].xfer_count = hhcd->hc[ch_num].XferSize - \
 8000b30:	687a      	ldr	r2, [r7, #4]
 8000b32:	68fb      	ldr	r3, [r7, #12]
 8000b34:	212c      	movs	r1, #44	; 0x2c
 8000b36:	fb01 f303 	mul.w	r3, r1, r3
 8000b3a:	4413      	add	r3, r2
 8000b3c:	3348      	adds	r3, #72	; 0x48
 8000b3e:	681a      	ldr	r2, [r3, #0]
                                    (USBx_HC(ch_num)->HCTSIZ & USB_OTG_HCTSIZ_XFRSIZ);
 8000b40:	68fb      	ldr	r3, [r7, #12]
 8000b42:	0159      	lsls	r1, r3, #5
 8000b44:	693b      	ldr	r3, [r7, #16]
 8000b46:	440b      	add	r3, r1
 8000b48:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 8000b4c:	691b      	ldr	r3, [r3, #16]
 8000b4e:	f3c3 0312 	ubfx	r3, r3, #0, #19
      hhcd->hc[ch_num].xfer_count = hhcd->hc[ch_num].XferSize - \
 8000b52:	1ad2      	subs	r2, r2, r3
 8000b54:	6879      	ldr	r1, [r7, #4]
 8000b56:	68fb      	ldr	r3, [r7, #12]
 8000b58:	202c      	movs	r0, #44	; 0x2c
 8000b5a:	fb00 f303 	mul.w	r3, r0, r3
 8000b5e:	440b      	add	r3, r1
 8000b60:	3350      	adds	r3, #80	; 0x50
 8000b62:	601a      	str	r2, [r3, #0]
    hhcd->hc[ch_num].state = HC_XFRC;
 8000b64:	687a      	ldr	r2, [r7, #4]
 8000b66:	68fb      	ldr	r3, [r7, #12]
 8000b68:	212c      	movs	r1, #44	; 0x2c
 8000b6a:	fb01 f303 	mul.w	r3, r1, r3
 8000b6e:	4413      	add	r3, r2
 8000b70:	3361      	adds	r3, #97	; 0x61
 8000b72:	2201      	movs	r2, #1
 8000b74:	701a      	strb	r2, [r3, #0]
    hhcd->hc[ch_num].ErrCnt = 0U;
 8000b76:	687a      	ldr	r2, [r7, #4]
 8000b78:	68fb      	ldr	r3, [r7, #12]
 8000b7a:	212c      	movs	r1, #44	; 0x2c
 8000b7c:	fb01 f303 	mul.w	r3, r1, r3
 8000b80:	4413      	add	r3, r2
 8000b82:	335c      	adds	r3, #92	; 0x5c
 8000b84:	2200      	movs	r2, #0
 8000b86:	601a      	str	r2, [r3, #0]
    __HAL_HCD_CLEAR_HC_INT(ch_num, USB_OTG_HCINT_XFRC);
 8000b88:	68fb      	ldr	r3, [r7, #12]
 8000b8a:	015a      	lsls	r2, r3, #5
 8000b8c:	693b      	ldr	r3, [r7, #16]
 8000b8e:	4413      	add	r3, r2
 8000b90:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 8000b94:	461a      	mov	r2, r3
 8000b96:	2301      	movs	r3, #1
 8000b98:	6093      	str	r3, [r2, #8]
    if ((hhcd->hc[ch_num].ep_type == EP_TYPE_CTRL) ||
 8000b9a:	687a      	ldr	r2, [r7, #4]
 8000b9c:	68fb      	ldr	r3, [r7, #12]
 8000b9e:	212c      	movs	r1, #44	; 0x2c
 8000ba0:	fb01 f303 	mul.w	r3, r1, r3
 8000ba4:	4413      	add	r3, r2
 8000ba6:	333f      	adds	r3, #63	; 0x3f
 8000ba8:	781b      	ldrb	r3, [r3, #0]
 8000baa:	2b00      	cmp	r3, #0
 8000bac:	d009      	beq.n	8000bc2 <HCD_HC_IN_IRQHandler+0x2b6>
        (hhcd->hc[ch_num].ep_type == EP_TYPE_BULK))
 8000bae:	687a      	ldr	r2, [r7, #4]
 8000bb0:	68fb      	ldr	r3, [r7, #12]
 8000bb2:	212c      	movs	r1, #44	; 0x2c
 8000bb4:	fb01 f303 	mul.w	r3, r1, r3
 8000bb8:	4413      	add	r3, r2
 8000bba:	333f      	adds	r3, #63	; 0x3f
 8000bbc:	781b      	ldrb	r3, [r3, #0]
    if ((hhcd->hc[ch_num].ep_type == EP_TYPE_CTRL) ||
 8000bbe:	2b02      	cmp	r3, #2
 8000bc0:	d111      	bne.n	8000be6 <HCD_HC_IN_IRQHandler+0x2da>
      (void)USB_HC_Halt(hhcd->Instance, (uint8_t)ch_num);
 8000bc2:	687b      	ldr	r3, [r7, #4]
 8000bc4:	681b      	ldr	r3, [r3, #0]
 8000bc6:	68fa      	ldr	r2, [r7, #12]
 8000bc8:	b2d2      	uxtb	r2, r2
 8000bca:	4611      	mov	r1, r2
 8000bcc:	4618      	mov	r0, r3
 8000bce:	f000 ffeb 	bl	8001ba8 <USB_HC_Halt>
      __HAL_HCD_CLEAR_HC_INT(ch_num, USB_OTG_HCINT_NAK);
 8000bd2:	68fb      	ldr	r3, [r7, #12]
 8000bd4:	015a      	lsls	r2, r3, #5
 8000bd6:	693b      	ldr	r3, [r7, #16]
 8000bd8:	4413      	add	r3, r2
 8000bda:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 8000bde:	461a      	mov	r2, r3
 8000be0:	2310      	movs	r3, #16
 8000be2:	6093      	str	r3, [r2, #8]
 8000be4:	e03a      	b.n	8000c5c <HCD_HC_IN_IRQHandler+0x350>
    else if ((hhcd->hc[ch_num].ep_type == EP_TYPE_INTR) ||
 8000be6:	687a      	ldr	r2, [r7, #4]
 8000be8:	68fb      	ldr	r3, [r7, #12]
 8000bea:	212c      	movs	r1, #44	; 0x2c
 8000bec:	fb01 f303 	mul.w	r3, r1, r3
 8000bf0:	4413      	add	r3, r2
 8000bf2:	333f      	adds	r3, #63	; 0x3f
 8000bf4:	781b      	ldrb	r3, [r3, #0]
 8000bf6:	2b03      	cmp	r3, #3
 8000bf8:	d009      	beq.n	8000c0e <HCD_HC_IN_IRQHandler+0x302>
             (hhcd->hc[ch_num].ep_type == EP_TYPE_ISOC))
 8000bfa:	687a      	ldr	r2, [r7, #4]
 8000bfc:	68fb      	ldr	r3, [r7, #12]
 8000bfe:	212c      	movs	r1, #44	; 0x2c
 8000c00:	fb01 f303 	mul.w	r3, r1, r3
 8000c04:	4413      	add	r3, r2
 8000c06:	333f      	adds	r3, #63	; 0x3f
 8000c08:	781b      	ldrb	r3, [r3, #0]
    else if ((hhcd->hc[ch_num].ep_type == EP_TYPE_INTR) ||
 8000c0a:	2b01      	cmp	r3, #1
 8000c0c:	d126      	bne.n	8000c5c <HCD_HC_IN_IRQHandler+0x350>
      USBx_HC(ch_num)->HCCHAR |= USB_OTG_HCCHAR_ODDFRM;
 8000c0e:	68fb      	ldr	r3, [r7, #12]
 8000c10:	015a      	lsls	r2, r3, #5
 8000c12:	693b      	ldr	r3, [r7, #16]
 8000c14:	4413      	add	r3, r2
 8000c16:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 8000c1a:	681b      	ldr	r3, [r3, #0]
 8000c1c:	68fa      	ldr	r2, [r7, #12]
 8000c1e:	0151      	lsls	r1, r2, #5
 8000c20:	693a      	ldr	r2, [r7, #16]
 8000c22:	440a      	add	r2, r1
 8000c24:	f502 62a0 	add.w	r2, r2, #1280	; 0x500
 8000c28:	f043 5300 	orr.w	r3, r3, #536870912	; 0x20000000
 8000c2c:	6013      	str	r3, [r2, #0]
      hhcd->hc[ch_num].urb_state = URB_DONE;
 8000c2e:	687a      	ldr	r2, [r7, #4]
 8000c30:	68fb      	ldr	r3, [r7, #12]
 8000c32:	212c      	movs	r1, #44	; 0x2c
 8000c34:	fb01 f303 	mul.w	r3, r1, r3
 8000c38:	4413      	add	r3, r2
 8000c3a:	3360      	adds	r3, #96	; 0x60
 8000c3c:	2201      	movs	r2, #1
 8000c3e:	701a      	strb	r2, [r3, #0]
      HAL_HCD_HC_NotifyURBChange_Callback(hhcd, (uint8_t)ch_num, hhcd->hc[ch_num].urb_state);
 8000c40:	68fb      	ldr	r3, [r7, #12]
 8000c42:	b2d9      	uxtb	r1, r3
 8000c44:	687a      	ldr	r2, [r7, #4]
 8000c46:	68fb      	ldr	r3, [r7, #12]
 8000c48:	202c      	movs	r0, #44	; 0x2c
 8000c4a:	fb00 f303 	mul.w	r3, r0, r3
 8000c4e:	4413      	add	r3, r2
 8000c50:	3360      	adds	r3, #96	; 0x60
 8000c52:	781b      	ldrb	r3, [r3, #0]
 8000c54:	461a      	mov	r2, r3
 8000c56:	6878      	ldr	r0, [r7, #4]
 8000c58:	f001 f9fd 	bl	8002056 <HAL_HCD_HC_NotifyURBChange_Callback>
    if (hhcd->Init.dma_enable == 1U)
 8000c5c:	687b      	ldr	r3, [r7, #4]
 8000c5e:	691b      	ldr	r3, [r3, #16]
 8000c60:	2b01      	cmp	r3, #1
 8000c62:	d12b      	bne.n	8000cbc <HCD_HC_IN_IRQHandler+0x3b0>
      if (((hhcd->hc[ch_num].XferSize / hhcd->hc[ch_num].max_packet) & 1U) != 0U)
 8000c64:	687a      	ldr	r2, [r7, #4]
 8000c66:	68fb      	ldr	r3, [r7, #12]
 8000c68:	212c      	movs	r1, #44	; 0x2c
 8000c6a:	fb01 f303 	mul.w	r3, r1, r3
 8000c6e:	4413      	add	r3, r2
 8000c70:	3348      	adds	r3, #72	; 0x48
 8000c72:	681b      	ldr	r3, [r3, #0]
 8000c74:	6879      	ldr	r1, [r7, #4]
 8000c76:	68fa      	ldr	r2, [r7, #12]
 8000c78:	202c      	movs	r0, #44	; 0x2c
 8000c7a:	fb00 f202 	mul.w	r2, r0, r2
 8000c7e:	440a      	add	r2, r1
 8000c80:	3240      	adds	r2, #64	; 0x40
 8000c82:	8812      	ldrh	r2, [r2, #0]
 8000c84:	fbb3 f3f2 	udiv	r3, r3, r2
 8000c88:	f003 0301 	and.w	r3, r3, #1
 8000c8c:	2b00      	cmp	r3, #0
 8000c8e:	f000 818e 	beq.w	8000fae <HCD_HC_IN_IRQHandler+0x6a2>
        hhcd->hc[ch_num].toggle_in ^= 1U;
 8000c92:	687a      	ldr	r2, [r7, #4]
 8000c94:	68fb      	ldr	r3, [r7, #12]
 8000c96:	212c      	movs	r1, #44	; 0x2c
 8000c98:	fb01 f303 	mul.w	r3, r1, r3
 8000c9c:	4413      	add	r3, r2
 8000c9e:	3354      	adds	r3, #84	; 0x54
 8000ca0:	781b      	ldrb	r3, [r3, #0]
 8000ca2:	f083 0301 	eor.w	r3, r3, #1
 8000ca6:	b2d8      	uxtb	r0, r3
 8000ca8:	687a      	ldr	r2, [r7, #4]
 8000caa:	68fb      	ldr	r3, [r7, #12]
 8000cac:	212c      	movs	r1, #44	; 0x2c
 8000cae:	fb01 f303 	mul.w	r3, r1, r3
 8000cb2:	4413      	add	r3, r2
 8000cb4:	3354      	adds	r3, #84	; 0x54
 8000cb6:	4602      	mov	r2, r0
 8000cb8:	701a      	strb	r2, [r3, #0]
}
 8000cba:	e178      	b.n	8000fae <HCD_HC_IN_IRQHandler+0x6a2>
      hhcd->hc[ch_num].toggle_in ^= 1U;
 8000cbc:	687a      	ldr	r2, [r7, #4]
 8000cbe:	68fb      	ldr	r3, [r7, #12]
 8000cc0:	212c      	movs	r1, #44	; 0x2c
 8000cc2:	fb01 f303 	mul.w	r3, r1, r3
 8000cc6:	4413      	add	r3, r2
 8000cc8:	3354      	adds	r3, #84	; 0x54
 8000cca:	781b      	ldrb	r3, [r3, #0]
 8000ccc:	f083 0301 	eor.w	r3, r3, #1
 8000cd0:	b2d8      	uxtb	r0, r3
 8000cd2:	687a      	ldr	r2, [r7, #4]
 8000cd4:	68fb      	ldr	r3, [r7, #12]
 8000cd6:	212c      	movs	r1, #44	; 0x2c
 8000cd8:	fb01 f303 	mul.w	r3, r1, r3
 8000cdc:	4413      	add	r3, r2
 8000cde:	3354      	adds	r3, #84	; 0x54
 8000ce0:	4602      	mov	r2, r0
 8000ce2:	701a      	strb	r2, [r3, #0]
}
 8000ce4:	e163      	b.n	8000fae <HCD_HC_IN_IRQHandler+0x6a2>
  else if ((USBx_HC(ch_num)->HCINT & USB_OTG_HCINT_CHH) == USB_OTG_HCINT_CHH)
 8000ce6:	68fb      	ldr	r3, [r7, #12]
 8000ce8:	015a      	lsls	r2, r3, #5
 8000cea:	693b      	ldr	r3, [r7, #16]
 8000cec:	4413      	add	r3, r2
 8000cee:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 8000cf2:	689b      	ldr	r3, [r3, #8]
 8000cf4:	f003 0302 	and.w	r3, r3, #2
 8000cf8:	2b02      	cmp	r3, #2
 8000cfa:	f040 80f6 	bne.w	8000eea <HCD_HC_IN_IRQHandler+0x5de>
    if (hhcd->hc[ch_num].state == HC_XFRC)
 8000cfe:	687a      	ldr	r2, [r7, #4]
 8000d00:	68fb      	ldr	r3, [r7, #12]
 8000d02:	212c      	movs	r1, #44	; 0x2c
 8000d04:	fb01 f303 	mul.w	r3, r1, r3
 8000d08:	4413      	add	r3, r2
 8000d0a:	3361      	adds	r3, #97	; 0x61
 8000d0c:	781b      	ldrb	r3, [r3, #0]
 8000d0e:	2b01      	cmp	r3, #1
 8000d10:	d109      	bne.n	8000d26 <HCD_HC_IN_IRQHandler+0x41a>
      hhcd->hc[ch_num].urb_state = URB_DONE;
 8000d12:	687a      	ldr	r2, [r7, #4]
 8000d14:	68fb      	ldr	r3, [r7, #12]
 8000d16:	212c      	movs	r1, #44	; 0x2c
 8000d18:	fb01 f303 	mul.w	r3, r1, r3
 8000d1c:	4413      	add	r3, r2
 8000d1e:	3360      	adds	r3, #96	; 0x60
 8000d20:	2201      	movs	r2, #1
 8000d22:	701a      	strb	r2, [r3, #0]
 8000d24:	e0c9      	b.n	8000eba <HCD_HC_IN_IRQHandler+0x5ae>
    else if (hhcd->hc[ch_num].state == HC_STALL)
 8000d26:	687a      	ldr	r2, [r7, #4]
 8000d28:	68fb      	ldr	r3, [r7, #12]
 8000d2a:	212c      	movs	r1, #44	; 0x2c
 8000d2c:	fb01 f303 	mul.w	r3, r1, r3
 8000d30:	4413      	add	r3, r2
 8000d32:	3361      	adds	r3, #97	; 0x61
 8000d34:	781b      	ldrb	r3, [r3, #0]
 8000d36:	2b05      	cmp	r3, #5
 8000d38:	d109      	bne.n	8000d4e <HCD_HC_IN_IRQHandler+0x442>
      hhcd->hc[ch_num].urb_state = URB_STALL;
 8000d3a:	687a      	ldr	r2, [r7, #4]
 8000d3c:	68fb      	ldr	r3, [r7, #12]
 8000d3e:	212c      	movs	r1, #44	; 0x2c
 8000d40:	fb01 f303 	mul.w	r3, r1, r3
 8000d44:	4413      	add	r3, r2
 8000d46:	3360      	adds	r3, #96	; 0x60
 8000d48:	2205      	movs	r2, #5
 8000d4a:	701a      	strb	r2, [r3, #0]
 8000d4c:	e0b5      	b.n	8000eba <HCD_HC_IN_IRQHandler+0x5ae>
    else if ((hhcd->hc[ch_num].state == HC_XACTERR) ||
 8000d4e:	687a      	ldr	r2, [r7, #4]
 8000d50:	68fb      	ldr	r3, [r7, #12]
 8000d52:	212c      	movs	r1, #44	; 0x2c
 8000d54:	fb01 f303 	mul.w	r3, r1, r3
 8000d58:	4413      	add	r3, r2
 8000d5a:	3361      	adds	r3, #97	; 0x61
 8000d5c:	781b      	ldrb	r3, [r3, #0]
 8000d5e:	2b06      	cmp	r3, #6
 8000d60:	d009      	beq.n	8000d76 <HCD_HC_IN_IRQHandler+0x46a>
             (hhcd->hc[ch_num].state == HC_DATATGLERR))
 8000d62:	687a      	ldr	r2, [r7, #4]
 8000d64:	68fb      	ldr	r3, [r7, #12]
 8000d66:	212c      	movs	r1, #44	; 0x2c
 8000d68:	fb01 f303 	mul.w	r3, r1, r3
 8000d6c:	4413      	add	r3, r2
 8000d6e:	3361      	adds	r3, #97	; 0x61
 8000d70:	781b      	ldrb	r3, [r3, #0]
    else if ((hhcd->hc[ch_num].state == HC_XACTERR) ||
 8000d72:	2b08      	cmp	r3, #8
 8000d74:	d150      	bne.n	8000e18 <HCD_HC_IN_IRQHandler+0x50c>
      hhcd->hc[ch_num].ErrCnt++;
 8000d76:	687a      	ldr	r2, [r7, #4]
 8000d78:	68fb      	ldr	r3, [r7, #12]
 8000d7a:	212c      	movs	r1, #44	; 0x2c
 8000d7c:	fb01 f303 	mul.w	r3, r1, r3
 8000d80:	4413      	add	r3, r2
 8000d82:	335c      	adds	r3, #92	; 0x5c
 8000d84:	681b      	ldr	r3, [r3, #0]
 8000d86:	1c5a      	adds	r2, r3, #1
 8000d88:	6879      	ldr	r1, [r7, #4]
 8000d8a:	68fb      	ldr	r3, [r7, #12]
 8000d8c:	202c      	movs	r0, #44	; 0x2c
 8000d8e:	fb00 f303 	mul.w	r3, r0, r3
 8000d92:	440b      	add	r3, r1
 8000d94:	335c      	adds	r3, #92	; 0x5c
 8000d96:	601a      	str	r2, [r3, #0]
      if (hhcd->hc[ch_num].ErrCnt > 2U)
 8000d98:	687a      	ldr	r2, [r7, #4]
 8000d9a:	68fb      	ldr	r3, [r7, #12]
 8000d9c:	212c      	movs	r1, #44	; 0x2c
 8000d9e:	fb01 f303 	mul.w	r3, r1, r3
 8000da2:	4413      	add	r3, r2
 8000da4:	335c      	adds	r3, #92	; 0x5c
 8000da6:	681b      	ldr	r3, [r3, #0]
 8000da8:	2b02      	cmp	r3, #2
 8000daa:	d912      	bls.n	8000dd2 <HCD_HC_IN_IRQHandler+0x4c6>
        hhcd->hc[ch_num].ErrCnt = 0U;
 8000dac:	687a      	ldr	r2, [r7, #4]
 8000dae:	68fb      	ldr	r3, [r7, #12]
 8000db0:	212c      	movs	r1, #44	; 0x2c
 8000db2:	fb01 f303 	mul.w	r3, r1, r3
 8000db6:	4413      	add	r3, r2
 8000db8:	335c      	adds	r3, #92	; 0x5c
 8000dba:	2200      	movs	r2, #0
 8000dbc:	601a      	str	r2, [r3, #0]
        hhcd->hc[ch_num].urb_state = URB_ERROR;
 8000dbe:	687a      	ldr	r2, [r7, #4]
 8000dc0:	68fb      	ldr	r3, [r7, #12]
 8000dc2:	212c      	movs	r1, #44	; 0x2c
 8000dc4:	fb01 f303 	mul.w	r3, r1, r3
 8000dc8:	4413      	add	r3, r2
 8000dca:	3360      	adds	r3, #96	; 0x60
 8000dcc:	2204      	movs	r2, #4
 8000dce:	701a      	strb	r2, [r3, #0]
      if (hhcd->hc[ch_num].ErrCnt > 2U)
 8000dd0:	e073      	b.n	8000eba <HCD_HC_IN_IRQHandler+0x5ae>
        hhcd->hc[ch_num].urb_state = URB_NOTREADY;
 8000dd2:	687a      	ldr	r2, [r7, #4]
 8000dd4:	68fb      	ldr	r3, [r7, #12]
 8000dd6:	212c      	movs	r1, #44	; 0x2c
 8000dd8:	fb01 f303 	mul.w	r3, r1, r3
 8000ddc:	4413      	add	r3, r2
 8000dde:	3360      	adds	r3, #96	; 0x60
 8000de0:	2202      	movs	r2, #2
 8000de2:	701a      	strb	r2, [r3, #0]
        tmpreg = USBx_HC(ch_num)->HCCHAR;
 8000de4:	68fb      	ldr	r3, [r7, #12]
 8000de6:	015a      	lsls	r2, r3, #5
 8000de8:	693b      	ldr	r3, [r7, #16]
 8000dea:	4413      	add	r3, r2
 8000dec:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 8000df0:	681b      	ldr	r3, [r3, #0]
 8000df2:	60bb      	str	r3, [r7, #8]
        tmpreg &= ~USB_OTG_HCCHAR_CHDIS;
 8000df4:	68bb      	ldr	r3, [r7, #8]
 8000df6:	f023 4380 	bic.w	r3, r3, #1073741824	; 0x40000000
 8000dfa:	60bb      	str	r3, [r7, #8]
        tmpreg |= USB_OTG_HCCHAR_CHENA;
 8000dfc:	68bb      	ldr	r3, [r7, #8]
 8000dfe:	f043 4300 	orr.w	r3, r3, #2147483648	; 0x80000000
 8000e02:	60bb      	str	r3, [r7, #8]
        USBx_HC(ch_num)->HCCHAR = tmpreg;
 8000e04:	68fb      	ldr	r3, [r7, #12]
 8000e06:	015a      	lsls	r2, r3, #5
 8000e08:	693b      	ldr	r3, [r7, #16]
 8000e0a:	4413      	add	r3, r2
 8000e0c:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 8000e10:	461a      	mov	r2, r3
 8000e12:	68bb      	ldr	r3, [r7, #8]
 8000e14:	6013      	str	r3, [r2, #0]
      if (hhcd->hc[ch_num].ErrCnt > 2U)
 8000e16:	e050      	b.n	8000eba <HCD_HC_IN_IRQHandler+0x5ae>
    else if (hhcd->hc[ch_num].state == HC_NAK)
 8000e18:	687a      	ldr	r2, [r7, #4]
 8000e1a:	68fb      	ldr	r3, [r7, #12]
 8000e1c:	212c      	movs	r1, #44	; 0x2c
 8000e1e:	fb01 f303 	mul.w	r3, r1, r3
 8000e22:	4413      	add	r3, r2
 8000e24:	3361      	adds	r3, #97	; 0x61
 8000e26:	781b      	ldrb	r3, [r3, #0]
 8000e28:	2b03      	cmp	r3, #3
 8000e2a:	d122      	bne.n	8000e72 <HCD_HC_IN_IRQHandler+0x566>
      hhcd->hc[ch_num].urb_state  = URB_NOTREADY;
 8000e2c:	687a      	ldr	r2, [r7, #4]
 8000e2e:	68fb      	ldr	r3, [r7, #12]
 8000e30:	212c      	movs	r1, #44	; 0x2c
 8000e32:	fb01 f303 	mul.w	r3, r1, r3
 8000e36:	4413      	add	r3, r2
 8000e38:	3360      	adds	r3, #96	; 0x60
 8000e3a:	2202      	movs	r2, #2
 8000e3c:	701a      	strb	r2, [r3, #0]
      tmpreg = USBx_HC(ch_num)->HCCHAR;
 8000e3e:	68fb      	ldr	r3, [r7, #12]
 8000e40:	015a      	lsls	r2, r3, #5
 8000e42:	693b      	ldr	r3, [r7, #16]
 8000e44:	4413      	add	r3, r2
 8000e46:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 8000e4a:	681b      	ldr	r3, [r3, #0]
 8000e4c:	60bb      	str	r3, [r7, #8]
      tmpreg &= ~USB_OTG_HCCHAR_CHDIS;
 8000e4e:	68bb      	ldr	r3, [r7, #8]
 8000e50:	f023 4380 	bic.w	r3, r3, #1073741824	; 0x40000000
 8000e54:	60bb      	str	r3, [r7, #8]
      tmpreg |= USB_OTG_HCCHAR_CHENA;
 8000e56:	68bb      	ldr	r3, [r7, #8]
 8000e58:	f043 4300 	orr.w	r3, r3, #2147483648	; 0x80000000
 8000e5c:	60bb      	str	r3, [r7, #8]
      USBx_HC(ch_num)->HCCHAR = tmpreg;
 8000e5e:	68fb      	ldr	r3, [r7, #12]
 8000e60:	015a      	lsls	r2, r3, #5
 8000e62:	693b      	ldr	r3, [r7, #16]
 8000e64:	4413      	add	r3, r2
 8000e66:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 8000e6a:	461a      	mov	r2, r3
 8000e6c:	68bb      	ldr	r3, [r7, #8]
 8000e6e:	6013      	str	r3, [r2, #0]
 8000e70:	e023      	b.n	8000eba <HCD_HC_IN_IRQHandler+0x5ae>
    else if (hhcd->hc[ch_num].state == HC_BBLERR)
 8000e72:	687a      	ldr	r2, [r7, #4]
 8000e74:	68fb      	ldr	r3, [r7, #12]
 8000e76:	212c      	movs	r1, #44	; 0x2c
 8000e78:	fb01 f303 	mul.w	r3, r1, r3
 8000e7c:	4413      	add	r3, r2
 8000e7e:	3361      	adds	r3, #97	; 0x61
 8000e80:	781b      	ldrb	r3, [r3, #0]
 8000e82:	2b07      	cmp	r3, #7
 8000e84:	d119      	bne.n	8000eba <HCD_HC_IN_IRQHandler+0x5ae>
      hhcd->hc[ch_num].ErrCnt++;
 8000e86:	687a      	ldr	r2, [r7, #4]
 8000e88:	68fb      	ldr	r3, [r7, #12]
 8000e8a:	212c      	movs	r1, #44	; 0x2c
 8000e8c:	fb01 f303 	mul.w	r3, r1, r3
 8000e90:	4413      	add	r3, r2
 8000e92:	335c      	adds	r3, #92	; 0x5c
 8000e94:	681b      	ldr	r3, [r3, #0]
 8000e96:	1c5a      	adds	r2, r3, #1
 8000e98:	6879      	ldr	r1, [r7, #4]
 8000e9a:	68fb      	ldr	r3, [r7, #12]
 8000e9c:	202c      	movs	r0, #44	; 0x2c
 8000e9e:	fb00 f303 	mul.w	r3, r0, r3
 8000ea2:	440b      	add	r3, r1
 8000ea4:	335c      	adds	r3, #92	; 0x5c
 8000ea6:	601a      	str	r2, [r3, #0]
      hhcd->hc[ch_num].urb_state = URB_ERROR;
 8000ea8:	687a      	ldr	r2, [r7, #4]
 8000eaa:	68fb      	ldr	r3, [r7, #12]
 8000eac:	212c      	movs	r1, #44	; 0x2c
 8000eae:	fb01 f303 	mul.w	r3, r1, r3
 8000eb2:	4413      	add	r3, r2
 8000eb4:	3360      	adds	r3, #96	; 0x60
 8000eb6:	2204      	movs	r2, #4
 8000eb8:	701a      	strb	r2, [r3, #0]
    __HAL_HCD_CLEAR_HC_INT(ch_num, USB_OTG_HCINT_CHH);
 8000eba:	68fb      	ldr	r3, [r7, #12]
 8000ebc:	015a      	lsls	r2, r3, #5
 8000ebe:	693b      	ldr	r3, [r7, #16]
 8000ec0:	4413      	add	r3, r2
 8000ec2:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 8000ec6:	461a      	mov	r2, r3
 8000ec8:	2302      	movs	r3, #2
 8000eca:	6093      	str	r3, [r2, #8]
    HAL_HCD_HC_NotifyURBChange_Callback(hhcd, (uint8_t)ch_num, hhcd->hc[ch_num].urb_state);
 8000ecc:	68fb      	ldr	r3, [r7, #12]
 8000ece:	b2d9      	uxtb	r1, r3
 8000ed0:	687a      	ldr	r2, [r7, #4]
 8000ed2:	68fb      	ldr	r3, [r7, #12]
 8000ed4:	202c      	movs	r0, #44	; 0x2c
 8000ed6:	fb00 f303 	mul.w	r3, r0, r3
 8000eda:	4413      	add	r3, r2
 8000edc:	3360      	adds	r3, #96	; 0x60
 8000ede:	781b      	ldrb	r3, [r3, #0]
 8000ee0:	461a      	mov	r2, r3
 8000ee2:	6878      	ldr	r0, [r7, #4]
 8000ee4:	f001 f8b7 	bl	8002056 <HAL_HCD_HC_NotifyURBChange_Callback>
}
 8000ee8:	e061      	b.n	8000fae <HCD_HC_IN_IRQHandler+0x6a2>
  else if ((USBx_HC(ch_num)->HCINT & USB_OTG_HCINT_NAK) == USB_OTG_HCINT_NAK)
 8000eea:	68fb      	ldr	r3, [r7, #12]
 8000eec:	015a      	lsls	r2, r3, #5
 8000eee:	693b      	ldr	r3, [r7, #16]
 8000ef0:	4413      	add	r3, r2
 8000ef2:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 8000ef6:	689b      	ldr	r3, [r3, #8]
 8000ef8:	f003 0310 	and.w	r3, r3, #16
 8000efc:	2b10      	cmp	r3, #16
 8000efe:	d156      	bne.n	8000fae <HCD_HC_IN_IRQHandler+0x6a2>
    if (hhcd->hc[ch_num].ep_type == EP_TYPE_INTR)
 8000f00:	687a      	ldr	r2, [r7, #4]
 8000f02:	68fb      	ldr	r3, [r7, #12]
 8000f04:	212c      	movs	r1, #44	; 0x2c
 8000f06:	fb01 f303 	mul.w	r3, r1, r3
 8000f0a:	4413      	add	r3, r2
 8000f0c:	333f      	adds	r3, #63	; 0x3f
 8000f0e:	781b      	ldrb	r3, [r3, #0]
 8000f10:	2b03      	cmp	r3, #3
 8000f12:	d111      	bne.n	8000f38 <HCD_HC_IN_IRQHandler+0x62c>
      hhcd->hc[ch_num].ErrCnt = 0U;
 8000f14:	687a      	ldr	r2, [r7, #4]
 8000f16:	68fb      	ldr	r3, [r7, #12]
 8000f18:	212c      	movs	r1, #44	; 0x2c
 8000f1a:	fb01 f303 	mul.w	r3, r1, r3
 8000f1e:	4413      	add	r3, r2
 8000f20:	335c      	adds	r3, #92	; 0x5c
 8000f22:	2200      	movs	r2, #0
 8000f24:	601a      	str	r2, [r3, #0]
      (void)USB_HC_Halt(hhcd->Instance, (uint8_t)ch_num);
 8000f26:	687b      	ldr	r3, [r7, #4]
 8000f28:	681b      	ldr	r3, [r3, #0]
 8000f2a:	68fa      	ldr	r2, [r7, #12]
 8000f2c:	b2d2      	uxtb	r2, r2
 8000f2e:	4611      	mov	r1, r2
 8000f30:	4618      	mov	r0, r3
 8000f32:	f000 fe39 	bl	8001ba8 <USB_HC_Halt>
 8000f36:	e031      	b.n	8000f9c <HCD_HC_IN_IRQHandler+0x690>
    else if ((hhcd->hc[ch_num].ep_type == EP_TYPE_CTRL) ||
 8000f38:	687a      	ldr	r2, [r7, #4]
 8000f3a:	68fb      	ldr	r3, [r7, #12]
 8000f3c:	212c      	movs	r1, #44	; 0x2c
 8000f3e:	fb01 f303 	mul.w	r3, r1, r3
 8000f42:	4413      	add	r3, r2
 8000f44:	333f      	adds	r3, #63	; 0x3f
 8000f46:	781b      	ldrb	r3, [r3, #0]
 8000f48:	2b00      	cmp	r3, #0
 8000f4a:	d009      	beq.n	8000f60 <HCD_HC_IN_IRQHandler+0x654>
             (hhcd->hc[ch_num].ep_type == EP_TYPE_BULK))
 8000f4c:	687a      	ldr	r2, [r7, #4]
 8000f4e:	68fb      	ldr	r3, [r7, #12]
 8000f50:	212c      	movs	r1, #44	; 0x2c
 8000f52:	fb01 f303 	mul.w	r3, r1, r3
 8000f56:	4413      	add	r3, r2
 8000f58:	333f      	adds	r3, #63	; 0x3f
 8000f5a:	781b      	ldrb	r3, [r3, #0]
    else if ((hhcd->hc[ch_num].ep_type == EP_TYPE_CTRL) ||
 8000f5c:	2b02      	cmp	r3, #2
 8000f5e:	d11d      	bne.n	8000f9c <HCD_HC_IN_IRQHandler+0x690>
      hhcd->hc[ch_num].ErrCnt = 0U;
 8000f60:	687a      	ldr	r2, [r7, #4]
 8000f62:	68fb      	ldr	r3, [r7, #12]
 8000f64:	212c      	movs	r1, #44	; 0x2c
 8000f66:	fb01 f303 	mul.w	r3, r1, r3
 8000f6a:	4413      	add	r3, r2
 8000f6c:	335c      	adds	r3, #92	; 0x5c
 8000f6e:	2200      	movs	r2, #0
 8000f70:	601a      	str	r2, [r3, #0]
      if (hhcd->Init.dma_enable == 0U)
 8000f72:	687b      	ldr	r3, [r7, #4]
 8000f74:	691b      	ldr	r3, [r3, #16]
 8000f76:	2b00      	cmp	r3, #0
 8000f78:	d110      	bne.n	8000f9c <HCD_HC_IN_IRQHandler+0x690>
        hhcd->hc[ch_num].state = HC_NAK;
 8000f7a:	687a      	ldr	r2, [r7, #4]
 8000f7c:	68fb      	ldr	r3, [r7, #12]
 8000f7e:	212c      	movs	r1, #44	; 0x2c
 8000f80:	fb01 f303 	mul.w	r3, r1, r3
 8000f84:	4413      	add	r3, r2
 8000f86:	3361      	adds	r3, #97	; 0x61
 8000f88:	2203      	movs	r2, #3
 8000f8a:	701a      	strb	r2, [r3, #0]
        (void)USB_HC_Halt(hhcd->Instance, (uint8_t)ch_num);
 8000f8c:	687b      	ldr	r3, [r7, #4]
 8000f8e:	681b      	ldr	r3, [r3, #0]
 8000f90:	68fa      	ldr	r2, [r7, #12]
 8000f92:	b2d2      	uxtb	r2, r2
 8000f94:	4611      	mov	r1, r2
 8000f96:	4618      	mov	r0, r3
 8000f98:	f000 fe06 	bl	8001ba8 <USB_HC_Halt>
    __HAL_HCD_CLEAR_HC_INT(ch_num, USB_OTG_HCINT_NAK);
 8000f9c:	68fb      	ldr	r3, [r7, #12]
 8000f9e:	015a      	lsls	r2, r3, #5
 8000fa0:	693b      	ldr	r3, [r7, #16]
 8000fa2:	4413      	add	r3, r2
 8000fa4:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 8000fa8:	461a      	mov	r2, r3
 8000faa:	2310      	movs	r3, #16
 8000fac:	6093      	str	r3, [r2, #8]
}
 8000fae:	bf00      	nop
 8000fb0:	3718      	adds	r7, #24
 8000fb2:	46bd      	mov	sp, r7
 8000fb4:	bd80      	pop	{r7, pc}

08000fb6 <HCD_HC_OUT_IRQHandler>:
  * @param  chnum Channel number.
  *         This parameter can be a value from 1 to 15
  * @retval none
  */
static void HCD_HC_OUT_IRQHandler(HCD_HandleTypeDef *hhcd, uint8_t chnum)
{
 8000fb6:	b580      	push	{r7, lr}
 8000fb8:	b088      	sub	sp, #32
 8000fba:	af00      	add	r7, sp, #0
 8000fbc:	6078      	str	r0, [r7, #4]
 8000fbe:	460b      	mov	r3, r1
 8000fc0:	70fb      	strb	r3, [r7, #3]
  USB_OTG_GlobalTypeDef *USBx = hhcd->Instance;
 8000fc2:	687b      	ldr	r3, [r7, #4]
 8000fc4:	681b      	ldr	r3, [r3, #0]
 8000fc6:	61fb      	str	r3, [r7, #28]
  uint32_t USBx_BASE = (uint32_t)USBx;
 8000fc8:	69fb      	ldr	r3, [r7, #28]
 8000fca:	61bb      	str	r3, [r7, #24]
  uint32_t ch_num = (uint32_t)chnum;
 8000fcc:	78fb      	ldrb	r3, [r7, #3]
 8000fce:	617b      	str	r3, [r7, #20]
  uint32_t tmpreg;
  uint32_t num_packets;

  if ((USBx_HC(ch_num)->HCINT & USB_OTG_HCINT_AHBERR) == USB_OTG_HCINT_AHBERR)
 8000fd0:	697b      	ldr	r3, [r7, #20]
 8000fd2:	015a      	lsls	r2, r3, #5
 8000fd4:	69bb      	ldr	r3, [r7, #24]
 8000fd6:	4413      	add	r3, r2
 8000fd8:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 8000fdc:	689b      	ldr	r3, [r3, #8]
 8000fde:	f003 0304 	and.w	r3, r3, #4
 8000fe2:	2b04      	cmp	r3, #4
 8000fe4:	d11a      	bne.n	800101c <HCD_HC_OUT_IRQHandler+0x66>
  {
    __HAL_HCD_CLEAR_HC_INT(ch_num, USB_OTG_HCINT_AHBERR);
 8000fe6:	697b      	ldr	r3, [r7, #20]
 8000fe8:	015a      	lsls	r2, r3, #5
 8000fea:	69bb      	ldr	r3, [r7, #24]
 8000fec:	4413      	add	r3, r2
 8000fee:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 8000ff2:	461a      	mov	r2, r3
 8000ff4:	2304      	movs	r3, #4
 8000ff6:	6093      	str	r3, [r2, #8]
    hhcd->hc[ch_num].state = HC_XACTERR;
 8000ff8:	687a      	ldr	r2, [r7, #4]
 8000ffa:	697b      	ldr	r3, [r7, #20]
 8000ffc:	212c      	movs	r1, #44	; 0x2c
 8000ffe:	fb01 f303 	mul.w	r3, r1, r3
 8001002:	4413      	add	r3, r2
 8001004:	3361      	adds	r3, #97	; 0x61
 8001006:	2206      	movs	r2, #6
 8001008:	701a      	strb	r2, [r3, #0]
    (void)USB_HC_Halt(hhcd->Instance, (uint8_t)ch_num);
 800100a:	687b      	ldr	r3, [r7, #4]
 800100c:	681b      	ldr	r3, [r3, #0]
 800100e:	697a      	ldr	r2, [r7, #20]
 8001010:	b2d2      	uxtb	r2, r2
 8001012:	4611      	mov	r1, r2
 8001014:	4618      	mov	r0, r3
 8001016:	f000 fdc7 	bl	8001ba8 <USB_HC_Halt>
  }
  else
  {
    /* ... */
  }
}
 800101a:	e331      	b.n	8001680 <HCD_HC_OUT_IRQHandler+0x6ca>
  else if ((USBx_HC(ch_num)->HCINT & USB_OTG_HCINT_ACK) == USB_OTG_HCINT_ACK)
 800101c:	697b      	ldr	r3, [r7, #20]
 800101e:	015a      	lsls	r2, r3, #5
 8001020:	69bb      	ldr	r3, [r7, #24]
 8001022:	4413      	add	r3, r2
 8001024:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 8001028:	689b      	ldr	r3, [r3, #8]
 800102a:	f003 0320 	and.w	r3, r3, #32
 800102e:	2b20      	cmp	r3, #32
 8001030:	d12e      	bne.n	8001090 <HCD_HC_OUT_IRQHandler+0xda>
    __HAL_HCD_CLEAR_HC_INT(ch_num, USB_OTG_HCINT_ACK);
 8001032:	697b      	ldr	r3, [r7, #20]
 8001034:	015a      	lsls	r2, r3, #5
 8001036:	69bb      	ldr	r3, [r7, #24]
 8001038:	4413      	add	r3, r2
 800103a:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 800103e:	461a      	mov	r2, r3
 8001040:	2320      	movs	r3, #32
 8001042:	6093      	str	r3, [r2, #8]
    if (hhcd->hc[ch_num].do_ping == 1U)
 8001044:	687a      	ldr	r2, [r7, #4]
 8001046:	697b      	ldr	r3, [r7, #20]
 8001048:	212c      	movs	r1, #44	; 0x2c
 800104a:	fb01 f303 	mul.w	r3, r1, r3
 800104e:	4413      	add	r3, r2
 8001050:	333d      	adds	r3, #61	; 0x3d
 8001052:	781b      	ldrb	r3, [r3, #0]
 8001054:	2b01      	cmp	r3, #1
 8001056:	f040 8313 	bne.w	8001680 <HCD_HC_OUT_IRQHandler+0x6ca>
      hhcd->hc[ch_num].do_ping = 0U;
 800105a:	687a      	ldr	r2, [r7, #4]
 800105c:	697b      	ldr	r3, [r7, #20]
 800105e:	212c      	movs	r1, #44	; 0x2c
 8001060:	fb01 f303 	mul.w	r3, r1, r3
 8001064:	4413      	add	r3, r2
 8001066:	333d      	adds	r3, #61	; 0x3d
 8001068:	2200      	movs	r2, #0
 800106a:	701a      	strb	r2, [r3, #0]
      hhcd->hc[ch_num].urb_state = URB_NOTREADY;
 800106c:	687a      	ldr	r2, [r7, #4]
 800106e:	697b      	ldr	r3, [r7, #20]
 8001070:	212c      	movs	r1, #44	; 0x2c
 8001072:	fb01 f303 	mul.w	r3, r1, r3
 8001076:	4413      	add	r3, r2
 8001078:	3360      	adds	r3, #96	; 0x60
 800107a:	2202      	movs	r2, #2
 800107c:	701a      	strb	r2, [r3, #0]
      (void)USB_HC_Halt(hhcd->Instance, (uint8_t)ch_num);
 800107e:	687b      	ldr	r3, [r7, #4]
 8001080:	681b      	ldr	r3, [r3, #0]
 8001082:	697a      	ldr	r2, [r7, #20]
 8001084:	b2d2      	uxtb	r2, r2
 8001086:	4611      	mov	r1, r2
 8001088:	4618      	mov	r0, r3
 800108a:	f000 fd8d 	bl	8001ba8 <USB_HC_Halt>
}
 800108e:	e2f7      	b.n	8001680 <HCD_HC_OUT_IRQHandler+0x6ca>
  else if ((USBx_HC(ch_num)->HCINT & USB_OTG_HCINT_FRMOR) == USB_OTG_HCINT_FRMOR)
 8001090:	697b      	ldr	r3, [r7, #20]
 8001092:	015a      	lsls	r2, r3, #5
 8001094:	69bb      	ldr	r3, [r7, #24]
 8001096:	4413      	add	r3, r2
 8001098:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 800109c:	689b      	ldr	r3, [r3, #8]
 800109e:	f403 7300 	and.w	r3, r3, #512	; 0x200
 80010a2:	f5b3 7f00 	cmp.w	r3, #512	; 0x200
 80010a6:	d112      	bne.n	80010ce <HCD_HC_OUT_IRQHandler+0x118>
    __HAL_HCD_CLEAR_HC_INT(ch_num, USB_OTG_HCINT_FRMOR);
 80010a8:	697b      	ldr	r3, [r7, #20]
 80010aa:	015a      	lsls	r2, r3, #5
 80010ac:	69bb      	ldr	r3, [r7, #24]
 80010ae:	4413      	add	r3, r2
 80010b0:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 80010b4:	461a      	mov	r2, r3
 80010b6:	f44f 7300 	mov.w	r3, #512	; 0x200
 80010ba:	6093      	str	r3, [r2, #8]
    (void)USB_HC_Halt(hhcd->Instance, (uint8_t)ch_num);
 80010bc:	687b      	ldr	r3, [r7, #4]
 80010be:	681b      	ldr	r3, [r3, #0]
 80010c0:	697a      	ldr	r2, [r7, #20]
 80010c2:	b2d2      	uxtb	r2, r2
 80010c4:	4611      	mov	r1, r2
 80010c6:	4618      	mov	r0, r3
 80010c8:	f000 fd6e 	bl	8001ba8 <USB_HC_Halt>
}
 80010cc:	e2d8      	b.n	8001680 <HCD_HC_OUT_IRQHandler+0x6ca>
  else if ((USBx_HC(ch_num)->HCINT & USB_OTG_HCINT_XFRC) == USB_OTG_HCINT_XFRC)
 80010ce:	697b      	ldr	r3, [r7, #20]
 80010d0:	015a      	lsls	r2, r3, #5
 80010d2:	69bb      	ldr	r3, [r7, #24]
 80010d4:	4413      	add	r3, r2
 80010d6:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 80010da:	689b      	ldr	r3, [r3, #8]
 80010dc:	f003 0301 	and.w	r3, r3, #1
 80010e0:	2b01      	cmp	r3, #1
 80010e2:	d140      	bne.n	8001166 <HCD_HC_OUT_IRQHandler+0x1b0>
    hhcd->hc[ch_num].ErrCnt = 0U;
 80010e4:	687a      	ldr	r2, [r7, #4]
 80010e6:	697b      	ldr	r3, [r7, #20]
 80010e8:	212c      	movs	r1, #44	; 0x2c
 80010ea:	fb01 f303 	mul.w	r3, r1, r3
 80010ee:	4413      	add	r3, r2
 80010f0:	335c      	adds	r3, #92	; 0x5c
 80010f2:	2200      	movs	r2, #0
 80010f4:	601a      	str	r2, [r3, #0]
    if ((USBx_HC(ch_num)->HCINT & USB_OTG_HCINT_NYET) == USB_OTG_HCINT_NYET)
 80010f6:	697b      	ldr	r3, [r7, #20]
 80010f8:	015a      	lsls	r2, r3, #5
 80010fa:	69bb      	ldr	r3, [r7, #24]
 80010fc:	4413      	add	r3, r2
 80010fe:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 8001102:	689b      	ldr	r3, [r3, #8]
 8001104:	f003 0340 	and.w	r3, r3, #64	; 0x40
 8001108:	2b40      	cmp	r3, #64	; 0x40
 800110a:	d111      	bne.n	8001130 <HCD_HC_OUT_IRQHandler+0x17a>
      hhcd->hc[ch_num].do_ping = 1U;
 800110c:	687a      	ldr	r2, [r7, #4]
 800110e:	697b      	ldr	r3, [r7, #20]
 8001110:	212c      	movs	r1, #44	; 0x2c
 8001112:	fb01 f303 	mul.w	r3, r1, r3
 8001116:	4413      	add	r3, r2
 8001118:	333d      	adds	r3, #61	; 0x3d
 800111a:	2201      	movs	r2, #1
 800111c:	701a      	strb	r2, [r3, #0]
      __HAL_HCD_CLEAR_HC_INT(ch_num, USB_OTG_HCINT_NYET);
 800111e:	697b      	ldr	r3, [r7, #20]
 8001120:	015a      	lsls	r2, r3, #5
 8001122:	69bb      	ldr	r3, [r7, #24]
 8001124:	4413      	add	r3, r2
 8001126:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 800112a:	461a      	mov	r2, r3
 800112c:	2340      	movs	r3, #64	; 0x40
 800112e:	6093      	str	r3, [r2, #8]
    __HAL_HCD_CLEAR_HC_INT(ch_num, USB_OTG_HCINT_XFRC);
 8001130:	697b      	ldr	r3, [r7, #20]
 8001132:	015a      	lsls	r2, r3, #5
 8001134:	69bb      	ldr	r3, [r7, #24]
 8001136:	4413      	add	r3, r2
 8001138:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 800113c:	461a      	mov	r2, r3
 800113e:	2301      	movs	r3, #1
 8001140:	6093      	str	r3, [r2, #8]
    hhcd->hc[ch_num].state = HC_XFRC;
 8001142:	687a      	ldr	r2, [r7, #4]
 8001144:	697b      	ldr	r3, [r7, #20]
 8001146:	212c      	movs	r1, #44	; 0x2c
 8001148:	fb01 f303 	mul.w	r3, r1, r3
 800114c:	4413      	add	r3, r2
 800114e:	3361      	adds	r3, #97	; 0x61
 8001150:	2201      	movs	r2, #1
 8001152:	701a      	strb	r2, [r3, #0]
    (void)USB_HC_Halt(hhcd->Instance, (uint8_t)ch_num);
 8001154:	687b      	ldr	r3, [r7, #4]
 8001156:	681b      	ldr	r3, [r3, #0]
 8001158:	697a      	ldr	r2, [r7, #20]
 800115a:	b2d2      	uxtb	r2, r2
 800115c:	4611      	mov	r1, r2
 800115e:	4618      	mov	r0, r3
 8001160:	f000 fd22 	bl	8001ba8 <USB_HC_Halt>
}
 8001164:	e28c      	b.n	8001680 <HCD_HC_OUT_IRQHandler+0x6ca>
  else if ((USBx_HC(ch_num)->HCINT & USB_OTG_HCINT_NYET) == USB_OTG_HCINT_NYET)
 8001166:	697b      	ldr	r3, [r7, #20]
 8001168:	015a      	lsls	r2, r3, #5
 800116a:	69bb      	ldr	r3, [r7, #24]
 800116c:	4413      	add	r3, r2
 800116e:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 8001172:	689b      	ldr	r3, [r3, #8]
 8001174:	f003 0340 	and.w	r3, r3, #64	; 0x40
 8001178:	2b40      	cmp	r3, #64	; 0x40
 800117a:	d12c      	bne.n	80011d6 <HCD_HC_OUT_IRQHandler+0x220>
    hhcd->hc[ch_num].state = HC_NYET;
 800117c:	687a      	ldr	r2, [r7, #4]
 800117e:	697b      	ldr	r3, [r7, #20]
 8001180:	212c      	movs	r1, #44	; 0x2c
 8001182:	fb01 f303 	mul.w	r3, r1, r3
 8001186:	4413      	add	r3, r2
 8001188:	3361      	adds	r3, #97	; 0x61
 800118a:	2204      	movs	r2, #4
 800118c:	701a      	strb	r2, [r3, #0]
    hhcd->hc[ch_num].do_ping = 1U;
 800118e:	687a      	ldr	r2, [r7, #4]
 8001190:	697b      	ldr	r3, [r7, #20]
 8001192:	212c      	movs	r1, #44	; 0x2c
 8001194:	fb01 f303 	mul.w	r3, r1, r3
 8001198:	4413      	add	r3, r2
 800119a:	333d      	adds	r3, #61	; 0x3d
 800119c:	2201      	movs	r2, #1
 800119e:	701a      	strb	r2, [r3, #0]
    hhcd->hc[ch_num].ErrCnt = 0U;
 80011a0:	687a      	ldr	r2, [r7, #4]
 80011a2:	697b      	ldr	r3, [r7, #20]
 80011a4:	212c      	movs	r1, #44	; 0x2c
 80011a6:	fb01 f303 	mul.w	r3, r1, r3
 80011aa:	4413      	add	r3, r2
 80011ac:	335c      	adds	r3, #92	; 0x5c
 80011ae:	2200      	movs	r2, #0
 80011b0:	601a      	str	r2, [r3, #0]
    (void)USB_HC_Halt(hhcd->Instance, (uint8_t)ch_num);
 80011b2:	687b      	ldr	r3, [r7, #4]
 80011b4:	681b      	ldr	r3, [r3, #0]
 80011b6:	697a      	ldr	r2, [r7, #20]
 80011b8:	b2d2      	uxtb	r2, r2
 80011ba:	4611      	mov	r1, r2
 80011bc:	4618      	mov	r0, r3
 80011be:	f000 fcf3 	bl	8001ba8 <USB_HC_Halt>
    __HAL_HCD_CLEAR_HC_INT(ch_num, USB_OTG_HCINT_NYET);
 80011c2:	697b      	ldr	r3, [r7, #20]
 80011c4:	015a      	lsls	r2, r3, #5
 80011c6:	69bb      	ldr	r3, [r7, #24]
 80011c8:	4413      	add	r3, r2
 80011ca:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 80011ce:	461a      	mov	r2, r3
 80011d0:	2340      	movs	r3, #64	; 0x40
 80011d2:	6093      	str	r3, [r2, #8]
}
 80011d4:	e254      	b.n	8001680 <HCD_HC_OUT_IRQHandler+0x6ca>
  else if ((USBx_HC(ch_num)->HCINT & USB_OTG_HCINT_STALL) == USB_OTG_HCINT_STALL)
 80011d6:	697b      	ldr	r3, [r7, #20]
 80011d8:	015a      	lsls	r2, r3, #5
 80011da:	69bb      	ldr	r3, [r7, #24]
 80011dc:	4413      	add	r3, r2
 80011de:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 80011e2:	689b      	ldr	r3, [r3, #8]
 80011e4:	f003 0308 	and.w	r3, r3, #8
 80011e8:	2b08      	cmp	r3, #8
 80011ea:	d11a      	bne.n	8001222 <HCD_HC_OUT_IRQHandler+0x26c>
    __HAL_HCD_CLEAR_HC_INT(ch_num, USB_OTG_HCINT_STALL);
 80011ec:	697b      	ldr	r3, [r7, #20]
 80011ee:	015a      	lsls	r2, r3, #5
 80011f0:	69bb      	ldr	r3, [r7, #24]
 80011f2:	4413      	add	r3, r2
 80011f4:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 80011f8:	461a      	mov	r2, r3
 80011fa:	2308      	movs	r3, #8
 80011fc:	6093      	str	r3, [r2, #8]
    hhcd->hc[ch_num].state = HC_STALL;
 80011fe:	687a      	ldr	r2, [r7, #4]
 8001200:	697b      	ldr	r3, [r7, #20]
 8001202:	212c      	movs	r1, #44	; 0x2c
 8001204:	fb01 f303 	mul.w	r3, r1, r3
 8001208:	4413      	add	r3, r2
 800120a:	3361      	adds	r3, #97	; 0x61
 800120c:	2205      	movs	r2, #5
 800120e:	701a      	strb	r2, [r3, #0]
    (void)USB_HC_Halt(hhcd->Instance, (uint8_t)ch_num);
 8001210:	687b      	ldr	r3, [r7, #4]
 8001212:	681b      	ldr	r3, [r3, #0]
 8001214:	697a      	ldr	r2, [r7, #20]
 8001216:	b2d2      	uxtb	r2, r2
 8001218:	4611      	mov	r1, r2
 800121a:	4618      	mov	r0, r3
 800121c:	f000 fcc4 	bl	8001ba8 <USB_HC_Halt>
}
 8001220:	e22e      	b.n	8001680 <HCD_HC_OUT_IRQHandler+0x6ca>
  else if ((USBx_HC(ch_num)->HCINT & USB_OTG_HCINT_NAK) == USB_OTG_HCINT_NAK)
 8001222:	697b      	ldr	r3, [r7, #20]
 8001224:	015a      	lsls	r2, r3, #5
 8001226:	69bb      	ldr	r3, [r7, #24]
 8001228:	4413      	add	r3, r2
 800122a:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 800122e:	689b      	ldr	r3, [r3, #8]
 8001230:	f003 0310 	and.w	r3, r3, #16
 8001234:	2b10      	cmp	r3, #16
 8001236:	d140      	bne.n	80012ba <HCD_HC_OUT_IRQHandler+0x304>
    hhcd->hc[ch_num].ErrCnt = 0U;
 8001238:	687a      	ldr	r2, [r7, #4]
 800123a:	697b      	ldr	r3, [r7, #20]
 800123c:	212c      	movs	r1, #44	; 0x2c
 800123e:	fb01 f303 	mul.w	r3, r1, r3
 8001242:	4413      	add	r3, r2
 8001244:	335c      	adds	r3, #92	; 0x5c
 8001246:	2200      	movs	r2, #0
 8001248:	601a      	str	r2, [r3, #0]
    hhcd->hc[ch_num].state = HC_NAK;
 800124a:	687a      	ldr	r2, [r7, #4]
 800124c:	697b      	ldr	r3, [r7, #20]
 800124e:	212c      	movs	r1, #44	; 0x2c
 8001250:	fb01 f303 	mul.w	r3, r1, r3
 8001254:	4413      	add	r3, r2
 8001256:	3361      	adds	r3, #97	; 0x61
 8001258:	2203      	movs	r2, #3
 800125a:	701a      	strb	r2, [r3, #0]
    if (hhcd->hc[ch_num].do_ping == 0U)
 800125c:	687a      	ldr	r2, [r7, #4]
 800125e:	697b      	ldr	r3, [r7, #20]
 8001260:	212c      	movs	r1, #44	; 0x2c
 8001262:	fb01 f303 	mul.w	r3, r1, r3
 8001266:	4413      	add	r3, r2
 8001268:	333d      	adds	r3, #61	; 0x3d
 800126a:	781b      	ldrb	r3, [r3, #0]
 800126c:	2b00      	cmp	r3, #0
 800126e:	d112      	bne.n	8001296 <HCD_HC_OUT_IRQHandler+0x2e0>
      if (hhcd->hc[ch_num].speed == HCD_DEVICE_SPEED_HIGH)
 8001270:	687a      	ldr	r2, [r7, #4]
 8001272:	697b      	ldr	r3, [r7, #20]
 8001274:	212c      	movs	r1, #44	; 0x2c
 8001276:	fb01 f303 	mul.w	r3, r1, r3
 800127a:	4413      	add	r3, r2
 800127c:	333c      	adds	r3, #60	; 0x3c
 800127e:	781b      	ldrb	r3, [r3, #0]
 8001280:	2b00      	cmp	r3, #0
 8001282:	d108      	bne.n	8001296 <HCD_HC_OUT_IRQHandler+0x2e0>
        hhcd->hc[ch_num].do_ping = 1U;
 8001284:	687a      	ldr	r2, [r7, #4]
 8001286:	697b      	ldr	r3, [r7, #20]
 8001288:	212c      	movs	r1, #44	; 0x2c
 800128a:	fb01 f303 	mul.w	r3, r1, r3
 800128e:	4413      	add	r3, r2
 8001290:	333d      	adds	r3, #61	; 0x3d
 8001292:	2201      	movs	r2, #1
 8001294:	701a      	strb	r2, [r3, #0]
    (void)USB_HC_Halt(hhcd->Instance, (uint8_t)ch_num);
 8001296:	687b      	ldr	r3, [r7, #4]
 8001298:	681b      	ldr	r3, [r3, #0]
 800129a:	697a      	ldr	r2, [r7, #20]
 800129c:	b2d2      	uxtb	r2, r2
 800129e:	4611      	mov	r1, r2
 80012a0:	4618      	mov	r0, r3
 80012a2:	f000 fc81 	bl	8001ba8 <USB_HC_Halt>
    __HAL_HCD_CLEAR_HC_INT(ch_num, USB_OTG_HCINT_NAK);
 80012a6:	697b      	ldr	r3, [r7, #20]
 80012a8:	015a      	lsls	r2, r3, #5
 80012aa:	69bb      	ldr	r3, [r7, #24]
 80012ac:	4413      	add	r3, r2
 80012ae:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 80012b2:	461a      	mov	r2, r3
 80012b4:	2310      	movs	r3, #16
 80012b6:	6093      	str	r3, [r2, #8]
}
 80012b8:	e1e2      	b.n	8001680 <HCD_HC_OUT_IRQHandler+0x6ca>
  else if ((USBx_HC(ch_num)->HCINT & USB_OTG_HCINT_TXERR) == USB_OTG_HCINT_TXERR)
 80012ba:	697b      	ldr	r3, [r7, #20]
 80012bc:	015a      	lsls	r2, r3, #5
 80012be:	69bb      	ldr	r3, [r7, #24]
 80012c0:	4413      	add	r3, r2
 80012c2:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 80012c6:	689b      	ldr	r3, [r3, #8]
 80012c8:	f003 0380 	and.w	r3, r3, #128	; 0x80
 80012cc:	2b80      	cmp	r3, #128	; 0x80
 80012ce:	d164      	bne.n	800139a <HCD_HC_OUT_IRQHandler+0x3e4>
    if (hhcd->Init.dma_enable == 0U)
 80012d0:	687b      	ldr	r3, [r7, #4]
 80012d2:	691b      	ldr	r3, [r3, #16]
 80012d4:	2b00      	cmp	r3, #0
 80012d6:	d111      	bne.n	80012fc <HCD_HC_OUT_IRQHandler+0x346>
      hhcd->hc[ch_num].state = HC_XACTERR;
 80012d8:	687a      	ldr	r2, [r7, #4]
 80012da:	697b      	ldr	r3, [r7, #20]
 80012dc:	212c      	movs	r1, #44	; 0x2c
 80012de:	fb01 f303 	mul.w	r3, r1, r3
 80012e2:	4413      	add	r3, r2
 80012e4:	3361      	adds	r3, #97	; 0x61
 80012e6:	2206      	movs	r2, #6
 80012e8:	701a      	strb	r2, [r3, #0]
      (void)USB_HC_Halt(hhcd->Instance, (uint8_t)ch_num);
 80012ea:	687b      	ldr	r3, [r7, #4]
 80012ec:	681b      	ldr	r3, [r3, #0]
 80012ee:	697a      	ldr	r2, [r7, #20]
 80012f0:	b2d2      	uxtb	r2, r2
 80012f2:	4611      	mov	r1, r2
 80012f4:	4618      	mov	r0, r3
 80012f6:	f000 fc57 	bl	8001ba8 <USB_HC_Halt>
 80012fa:	e044      	b.n	8001386 <HCD_HC_OUT_IRQHandler+0x3d0>
      hhcd->hc[ch_num].ErrCnt++;
 80012fc:	687a      	ldr	r2, [r7, #4]
 80012fe:	697b      	ldr	r3, [r7, #20]
 8001300:	212c      	movs	r1, #44	; 0x2c
 8001302:	fb01 f303 	mul.w	r3, r1, r3
 8001306:	4413      	add	r3, r2
 8001308:	335c      	adds	r3, #92	; 0x5c
 800130a:	681b      	ldr	r3, [r3, #0]
 800130c:	1c5a      	adds	r2, r3, #1
 800130e:	6879      	ldr	r1, [r7, #4]
 8001310:	697b      	ldr	r3, [r7, #20]
 8001312:	202c      	movs	r0, #44	; 0x2c
 8001314:	fb00 f303 	mul.w	r3, r0, r3
 8001318:	440b      	add	r3, r1
 800131a:	335c      	adds	r3, #92	; 0x5c
 800131c:	601a      	str	r2, [r3, #0]
      if (hhcd->hc[ch_num].ErrCnt > 2U)
 800131e:	687a      	ldr	r2, [r7, #4]
 8001320:	697b      	ldr	r3, [r7, #20]
 8001322:	212c      	movs	r1, #44	; 0x2c
 8001324:	fb01 f303 	mul.w	r3, r1, r3
 8001328:	4413      	add	r3, r2
 800132a:	335c      	adds	r3, #92	; 0x5c
 800132c:	681b      	ldr	r3, [r3, #0]
 800132e:	2b02      	cmp	r3, #2
 8001330:	d920      	bls.n	8001374 <HCD_HC_OUT_IRQHandler+0x3be>
        hhcd->hc[ch_num].ErrCnt = 0U;
 8001332:	687a      	ldr	r2, [r7, #4]
 8001334:	697b      	ldr	r3, [r7, #20]
 8001336:	212c      	movs	r1, #44	; 0x2c
 8001338:	fb01 f303 	mul.w	r3, r1, r3
 800133c:	4413      	add	r3, r2
 800133e:	335c      	adds	r3, #92	; 0x5c
 8001340:	2200      	movs	r2, #0
 8001342:	601a      	str	r2, [r3, #0]
        hhcd->hc[ch_num].urb_state = URB_ERROR;
 8001344:	687a      	ldr	r2, [r7, #4]
 8001346:	697b      	ldr	r3, [r7, #20]
 8001348:	212c      	movs	r1, #44	; 0x2c
 800134a:	fb01 f303 	mul.w	r3, r1, r3
 800134e:	4413      	add	r3, r2
 8001350:	3360      	adds	r3, #96	; 0x60
 8001352:	2204      	movs	r2, #4
 8001354:	701a      	strb	r2, [r3, #0]
        HAL_HCD_HC_NotifyURBChange_Callback(hhcd, (uint8_t)ch_num, hhcd->hc[ch_num].urb_state);
 8001356:	697b      	ldr	r3, [r7, #20]
 8001358:	b2d9      	uxtb	r1, r3
 800135a:	687a      	ldr	r2, [r7, #4]
 800135c:	697b      	ldr	r3, [r7, #20]
 800135e:	202c      	movs	r0, #44	; 0x2c
 8001360:	fb00 f303 	mul.w	r3, r0, r3
 8001364:	4413      	add	r3, r2
 8001366:	3360      	adds	r3, #96	; 0x60
 8001368:	781b      	ldrb	r3, [r3, #0]
 800136a:	461a      	mov	r2, r3
 800136c:	6878      	ldr	r0, [r7, #4]
 800136e:	f000 fe72 	bl	8002056 <HAL_HCD_HC_NotifyURBChange_Callback>
 8001372:	e008      	b.n	8001386 <HCD_HC_OUT_IRQHandler+0x3d0>
        hhcd->hc[ch_num].urb_state = URB_NOTREADY;
 8001374:	687a      	ldr	r2, [r7, #4]
 8001376:	697b      	ldr	r3, [r7, #20]
 8001378:	212c      	movs	r1, #44	; 0x2c
 800137a:	fb01 f303 	mul.w	r3, r1, r3
 800137e:	4413      	add	r3, r2
 8001380:	3360      	adds	r3, #96	; 0x60
 8001382:	2202      	movs	r2, #2
 8001384:	701a      	strb	r2, [r3, #0]
    __HAL_HCD_CLEAR_HC_INT(ch_num, USB_OTG_HCINT_TXERR);
 8001386:	697b      	ldr	r3, [r7, #20]
 8001388:	015a      	lsls	r2, r3, #5
 800138a:	69bb      	ldr	r3, [r7, #24]
 800138c:	4413      	add	r3, r2
 800138e:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 8001392:	461a      	mov	r2, r3
 8001394:	2380      	movs	r3, #128	; 0x80
 8001396:	6093      	str	r3, [r2, #8]
}
 8001398:	e172      	b.n	8001680 <HCD_HC_OUT_IRQHandler+0x6ca>
  else if ((USBx_HC(ch_num)->HCINT & USB_OTG_HCINT_DTERR) == USB_OTG_HCINT_DTERR)
 800139a:	697b      	ldr	r3, [r7, #20]
 800139c:	015a      	lsls	r2, r3, #5
 800139e:	69bb      	ldr	r3, [r7, #24]
 80013a0:	4413      	add	r3, r2
 80013a2:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 80013a6:	689b      	ldr	r3, [r3, #8]
 80013a8:	f403 6380 	and.w	r3, r3, #1024	; 0x400
 80013ac:	f5b3 6f80 	cmp.w	r3, #1024	; 0x400
 80013b0:	d11b      	bne.n	80013ea <HCD_HC_OUT_IRQHandler+0x434>
    hhcd->hc[ch_num].state = HC_DATATGLERR;
 80013b2:	687a      	ldr	r2, [r7, #4]
 80013b4:	697b      	ldr	r3, [r7, #20]
 80013b6:	212c      	movs	r1, #44	; 0x2c
 80013b8:	fb01 f303 	mul.w	r3, r1, r3
 80013bc:	4413      	add	r3, r2
 80013be:	3361      	adds	r3, #97	; 0x61
 80013c0:	2208      	movs	r2, #8
 80013c2:	701a      	strb	r2, [r3, #0]
    (void)USB_HC_Halt(hhcd->Instance, (uint8_t)ch_num);
 80013c4:	687b      	ldr	r3, [r7, #4]
 80013c6:	681b      	ldr	r3, [r3, #0]
 80013c8:	697a      	ldr	r2, [r7, #20]
 80013ca:	b2d2      	uxtb	r2, r2
 80013cc:	4611      	mov	r1, r2
 80013ce:	4618      	mov	r0, r3
 80013d0:	f000 fbea 	bl	8001ba8 <USB_HC_Halt>
    __HAL_HCD_CLEAR_HC_INT(ch_num, USB_OTG_HCINT_DTERR);
 80013d4:	697b      	ldr	r3, [r7, #20]
 80013d6:	015a      	lsls	r2, r3, #5
 80013d8:	69bb      	ldr	r3, [r7, #24]
 80013da:	4413      	add	r3, r2
 80013dc:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 80013e0:	461a      	mov	r2, r3
 80013e2:	f44f 6380 	mov.w	r3, #1024	; 0x400
 80013e6:	6093      	str	r3, [r2, #8]
}
 80013e8:	e14a      	b.n	8001680 <HCD_HC_OUT_IRQHandler+0x6ca>
  else if ((USBx_HC(ch_num)->HCINT & USB_OTG_HCINT_CHH) == USB_OTG_HCINT_CHH)
 80013ea:	697b      	ldr	r3, [r7, #20]
 80013ec:	015a      	lsls	r2, r3, #5
 80013ee:	69bb      	ldr	r3, [r7, #24]
 80013f0:	4413      	add	r3, r2
 80013f2:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 80013f6:	689b      	ldr	r3, [r3, #8]
 80013f8:	f003 0302 	and.w	r3, r3, #2
 80013fc:	2b02      	cmp	r3, #2
 80013fe:	f040 813f 	bne.w	8001680 <HCD_HC_OUT_IRQHandler+0x6ca>
    if (hhcd->hc[ch_num].state == HC_XFRC)
 8001402:	687a      	ldr	r2, [r7, #4]
 8001404:	697b      	ldr	r3, [r7, #20]
 8001406:	212c      	movs	r1, #44	; 0x2c
 8001408:	fb01 f303 	mul.w	r3, r1, r3
 800140c:	4413      	add	r3, r2
 800140e:	3361      	adds	r3, #97	; 0x61
 8001410:	781b      	ldrb	r3, [r3, #0]
 8001412:	2b01      	cmp	r3, #1
 8001414:	d17d      	bne.n	8001512 <HCD_HC_OUT_IRQHandler+0x55c>
      hhcd->hc[ch_num].urb_state  = URB_DONE;
 8001416:	687a      	ldr	r2, [r7, #4]
 8001418:	697b      	ldr	r3, [r7, #20]
 800141a:	212c      	movs	r1, #44	; 0x2c
 800141c:	fb01 f303 	mul.w	r3, r1, r3
 8001420:	4413      	add	r3, r2
 8001422:	3360      	adds	r3, #96	; 0x60
 8001424:	2201      	movs	r2, #1
 8001426:	701a      	strb	r2, [r3, #0]
      if ((hhcd->hc[ch_num].ep_type == EP_TYPE_BULK) ||
 8001428:	687a      	ldr	r2, [r7, #4]
 800142a:	697b      	ldr	r3, [r7, #20]
 800142c:	212c      	movs	r1, #44	; 0x2c
 800142e:	fb01 f303 	mul.w	r3, r1, r3
 8001432:	4413      	add	r3, r2
 8001434:	333f      	adds	r3, #63	; 0x3f
 8001436:	781b      	ldrb	r3, [r3, #0]
 8001438:	2b02      	cmp	r3, #2
 800143a:	d00a      	beq.n	8001452 <HCD_HC_OUT_IRQHandler+0x49c>
          (hhcd->hc[ch_num].ep_type == EP_TYPE_INTR))
 800143c:	687a      	ldr	r2, [r7, #4]
 800143e:	697b      	ldr	r3, [r7, #20]
 8001440:	212c      	movs	r1, #44	; 0x2c
 8001442:	fb01 f303 	mul.w	r3, r1, r3
 8001446:	4413      	add	r3, r2
 8001448:	333f      	adds	r3, #63	; 0x3f
 800144a:	781b      	ldrb	r3, [r3, #0]
      if ((hhcd->hc[ch_num].ep_type == EP_TYPE_BULK) ||
 800144c:	2b03      	cmp	r3, #3
 800144e:	f040 8100 	bne.w	8001652 <HCD_HC_OUT_IRQHandler+0x69c>
        if (hhcd->Init.dma_enable == 0U)
 8001452:	687b      	ldr	r3, [r7, #4]
 8001454:	691b      	ldr	r3, [r3, #16]
 8001456:	2b00      	cmp	r3, #0
 8001458:	d113      	bne.n	8001482 <HCD_HC_OUT_IRQHandler+0x4cc>
          hhcd->hc[ch_num].toggle_out ^= 1U;
 800145a:	687a      	ldr	r2, [r7, #4]
 800145c:	697b      	ldr	r3, [r7, #20]
 800145e:	212c      	movs	r1, #44	; 0x2c
 8001460:	fb01 f303 	mul.w	r3, r1, r3
 8001464:	4413      	add	r3, r2
 8001466:	3355      	adds	r3, #85	; 0x55
 8001468:	781b      	ldrb	r3, [r3, #0]
 800146a:	f083 0301 	eor.w	r3, r3, #1
 800146e:	b2d8      	uxtb	r0, r3
 8001470:	687a      	ldr	r2, [r7, #4]
 8001472:	697b      	ldr	r3, [r7, #20]
 8001474:	212c      	movs	r1, #44	; 0x2c
 8001476:	fb01 f303 	mul.w	r3, r1, r3
 800147a:	4413      	add	r3, r2
 800147c:	3355      	adds	r3, #85	; 0x55
 800147e:	4602      	mov	r2, r0
 8001480:	701a      	strb	r2, [r3, #0]
        if ((hhcd->Init.dma_enable == 1U) && (hhcd->hc[ch_num].xfer_len > 0U))
 8001482:	687b      	ldr	r3, [r7, #4]
 8001484:	691b      	ldr	r3, [r3, #16]
 8001486:	2b01      	cmp	r3, #1
 8001488:	f040 80e3 	bne.w	8001652 <HCD_HC_OUT_IRQHandler+0x69c>
 800148c:	687a      	ldr	r2, [r7, #4]
 800148e:	697b      	ldr	r3, [r7, #20]
 8001490:	212c      	movs	r1, #44	; 0x2c
 8001492:	fb01 f303 	mul.w	r3, r1, r3
 8001496:	4413      	add	r3, r2
 8001498:	334c      	adds	r3, #76	; 0x4c
 800149a:	681b      	ldr	r3, [r3, #0]
 800149c:	2b00      	cmp	r3, #0
 800149e:	f000 80d8 	beq.w	8001652 <HCD_HC_OUT_IRQHandler+0x69c>
          num_packets = (hhcd->hc[ch_num].xfer_len + hhcd->hc[ch_num].max_packet - 1U) / hhcd->hc[ch_num].max_packet;
 80014a2:	687a      	ldr	r2, [r7, #4]
 80014a4:	697b      	ldr	r3, [r7, #20]
 80014a6:	212c      	movs	r1, #44	; 0x2c
 80014a8:	fb01 f303 	mul.w	r3, r1, r3
 80014ac:	4413      	add	r3, r2
 80014ae:	334c      	adds	r3, #76	; 0x4c
 80014b0:	681b      	ldr	r3, [r3, #0]
 80014b2:	6879      	ldr	r1, [r7, #4]
 80014b4:	697a      	ldr	r2, [r7, #20]
 80014b6:	202c      	movs	r0, #44	; 0x2c
 80014b8:	fb00 f202 	mul.w	r2, r0, r2
 80014bc:	440a      	add	r2, r1
 80014be:	3240      	adds	r2, #64	; 0x40
 80014c0:	8812      	ldrh	r2, [r2, #0]
 80014c2:	4413      	add	r3, r2
 80014c4:	3b01      	subs	r3, #1
 80014c6:	6879      	ldr	r1, [r7, #4]
 80014c8:	697a      	ldr	r2, [r7, #20]
 80014ca:	202c      	movs	r0, #44	; 0x2c
 80014cc:	fb00 f202 	mul.w	r2, r0, r2
 80014d0:	440a      	add	r2, r1
 80014d2:	3240      	adds	r2, #64	; 0x40
 80014d4:	8812      	ldrh	r2, [r2, #0]
 80014d6:	fbb3 f3f2 	udiv	r3, r3, r2
 80014da:	60fb      	str	r3, [r7, #12]
          if ((num_packets & 1U) != 0U)
 80014dc:	68fb      	ldr	r3, [r7, #12]
 80014de:	f003 0301 	and.w	r3, r3, #1
 80014e2:	2b00      	cmp	r3, #0
 80014e4:	f000 80b5 	beq.w	8001652 <HCD_HC_OUT_IRQHandler+0x69c>
            hhcd->hc[ch_num].toggle_out ^= 1U;
 80014e8:	687a      	ldr	r2, [r7, #4]
 80014ea:	697b      	ldr	r3, [r7, #20]
 80014ec:	212c      	movs	r1, #44	; 0x2c
 80014ee:	fb01 f303 	mul.w	r3, r1, r3
 80014f2:	4413      	add	r3, r2
 80014f4:	3355      	adds	r3, #85	; 0x55
 80014f6:	781b      	ldrb	r3, [r3, #0]
 80014f8:	f083 0301 	eor.w	r3, r3, #1
 80014fc:	b2d8      	uxtb	r0, r3
 80014fe:	687a      	ldr	r2, [r7, #4]
 8001500:	697b      	ldr	r3, [r7, #20]
 8001502:	212c      	movs	r1, #44	; 0x2c
 8001504:	fb01 f303 	mul.w	r3, r1, r3
 8001508:	4413      	add	r3, r2
 800150a:	3355      	adds	r3, #85	; 0x55
 800150c:	4602      	mov	r2, r0
 800150e:	701a      	strb	r2, [r3, #0]
 8001510:	e09f      	b.n	8001652 <HCD_HC_OUT_IRQHandler+0x69c>
    else if (hhcd->hc[ch_num].state == HC_NAK)
 8001512:	687a      	ldr	r2, [r7, #4]
 8001514:	697b      	ldr	r3, [r7, #20]
 8001516:	212c      	movs	r1, #44	; 0x2c
 8001518:	fb01 f303 	mul.w	r3, r1, r3
 800151c:	4413      	add	r3, r2
 800151e:	3361      	adds	r3, #97	; 0x61
 8001520:	781b      	ldrb	r3, [r3, #0]
 8001522:	2b03      	cmp	r3, #3
 8001524:	d109      	bne.n	800153a <HCD_HC_OUT_IRQHandler+0x584>
      hhcd->hc[ch_num].urb_state = URB_NOTREADY;
 8001526:	687a      	ldr	r2, [r7, #4]
 8001528:	697b      	ldr	r3, [r7, #20]
 800152a:	212c      	movs	r1, #44	; 0x2c
 800152c:	fb01 f303 	mul.w	r3, r1, r3
 8001530:	4413      	add	r3, r2
 8001532:	3360      	adds	r3, #96	; 0x60
 8001534:	2202      	movs	r2, #2
 8001536:	701a      	strb	r2, [r3, #0]
 8001538:	e08b      	b.n	8001652 <HCD_HC_OUT_IRQHandler+0x69c>
    else if (hhcd->hc[ch_num].state == HC_NYET)
 800153a:	687a      	ldr	r2, [r7, #4]
 800153c:	697b      	ldr	r3, [r7, #20]
 800153e:	212c      	movs	r1, #44	; 0x2c
 8001540:	fb01 f303 	mul.w	r3, r1, r3
 8001544:	4413      	add	r3, r2
 8001546:	3361      	adds	r3, #97	; 0x61
 8001548:	781b      	ldrb	r3, [r3, #0]
 800154a:	2b04      	cmp	r3, #4
 800154c:	d109      	bne.n	8001562 <HCD_HC_OUT_IRQHandler+0x5ac>
      hhcd->hc[ch_num].urb_state  = URB_NOTREADY;
 800154e:	687a      	ldr	r2, [r7, #4]
 8001550:	697b      	ldr	r3, [r7, #20]
 8001552:	212c      	movs	r1, #44	; 0x2c
 8001554:	fb01 f303 	mul.w	r3, r1, r3
 8001558:	4413      	add	r3, r2
 800155a:	3360      	adds	r3, #96	; 0x60
 800155c:	2202      	movs	r2, #2
 800155e:	701a      	strb	r2, [r3, #0]
 8001560:	e077      	b.n	8001652 <HCD_HC_OUT_IRQHandler+0x69c>
    else if (hhcd->hc[ch_num].state == HC_STALL)
 8001562:	687a      	ldr	r2, [r7, #4]
 8001564:	697b      	ldr	r3, [r7, #20]
 8001566:	212c      	movs	r1, #44	; 0x2c
 8001568:	fb01 f303 	mul.w	r3, r1, r3
 800156c:	4413      	add	r3, r2
 800156e:	3361      	adds	r3, #97	; 0x61
 8001570:	781b      	ldrb	r3, [r3, #0]
 8001572:	2b05      	cmp	r3, #5
 8001574:	d109      	bne.n	800158a <HCD_HC_OUT_IRQHandler+0x5d4>
      hhcd->hc[ch_num].urb_state  = URB_STALL;
 8001576:	687a      	ldr	r2, [r7, #4]
 8001578:	697b      	ldr	r3, [r7, #20]
 800157a:	212c      	movs	r1, #44	; 0x2c
 800157c:	fb01 f303 	mul.w	r3, r1, r3
 8001580:	4413      	add	r3, r2
 8001582:	3360      	adds	r3, #96	; 0x60
 8001584:	2205      	movs	r2, #5
 8001586:	701a      	strb	r2, [r3, #0]
 8001588:	e063      	b.n	8001652 <HCD_HC_OUT_IRQHandler+0x69c>
    else if ((hhcd->hc[ch_num].state == HC_XACTERR) ||
 800158a:	687a      	ldr	r2, [r7, #4]
 800158c:	697b      	ldr	r3, [r7, #20]
 800158e:	212c      	movs	r1, #44	; 0x2c
 8001590:	fb01 f303 	mul.w	r3, r1, r3
 8001594:	4413      	add	r3, r2
 8001596:	3361      	adds	r3, #97	; 0x61
 8001598:	781b      	ldrb	r3, [r3, #0]
 800159a:	2b06      	cmp	r3, #6
 800159c:	d009      	beq.n	80015b2 <HCD_HC_OUT_IRQHandler+0x5fc>
             (hhcd->hc[ch_num].state == HC_DATATGLERR))
 800159e:	687a      	ldr	r2, [r7, #4]
 80015a0:	697b      	ldr	r3, [r7, #20]
 80015a2:	212c      	movs	r1, #44	; 0x2c
 80015a4:	fb01 f303 	mul.w	r3, r1, r3
 80015a8:	4413      	add	r3, r2
 80015aa:	3361      	adds	r3, #97	; 0x61
 80015ac:	781b      	ldrb	r3, [r3, #0]
    else if ((hhcd->hc[ch_num].state == HC_XACTERR) ||
 80015ae:	2b08      	cmp	r3, #8
 80015b0:	d14f      	bne.n	8001652 <HCD_HC_OUT_IRQHandler+0x69c>
      hhcd->hc[ch_num].ErrCnt++;
 80015b2:	687a      	ldr	r2, [r7, #4]
 80015b4:	697b      	ldr	r3, [r7, #20]
 80015b6:	212c      	movs	r1, #44	; 0x2c
 80015b8:	fb01 f303 	mul.w	r3, r1, r3
 80015bc:	4413      	add	r3, r2
 80015be:	335c      	adds	r3, #92	; 0x5c
 80015c0:	681b      	ldr	r3, [r3, #0]
 80015c2:	1c5a      	adds	r2, r3, #1
 80015c4:	6879      	ldr	r1, [r7, #4]
 80015c6:	697b      	ldr	r3, [r7, #20]
 80015c8:	202c      	movs	r0, #44	; 0x2c
 80015ca:	fb00 f303 	mul.w	r3, r0, r3
 80015ce:	440b      	add	r3, r1
 80015d0:	335c      	adds	r3, #92	; 0x5c
 80015d2:	601a      	str	r2, [r3, #0]
      if (hhcd->hc[ch_num].ErrCnt > 2U)
 80015d4:	687a      	ldr	r2, [r7, #4]
 80015d6:	697b      	ldr	r3, [r7, #20]
 80015d8:	212c      	movs	r1, #44	; 0x2c
 80015da:	fb01 f303 	mul.w	r3, r1, r3
 80015de:	4413      	add	r3, r2
 80015e0:	335c      	adds	r3, #92	; 0x5c
 80015e2:	681b      	ldr	r3, [r3, #0]
 80015e4:	2b02      	cmp	r3, #2
 80015e6:	d912      	bls.n	800160e <HCD_HC_OUT_IRQHandler+0x658>
        hhcd->hc[ch_num].ErrCnt = 0U;
 80015e8:	687a      	ldr	r2, [r7, #4]
 80015ea:	697b      	ldr	r3, [r7, #20]
 80015ec:	212c      	movs	r1, #44	; 0x2c
 80015ee:	fb01 f303 	mul.w	r3, r1, r3
 80015f2:	4413      	add	r3, r2
 80015f4:	335c      	adds	r3, #92	; 0x5c
 80015f6:	2200      	movs	r2, #0
 80015f8:	601a      	str	r2, [r3, #0]
        hhcd->hc[ch_num].urb_state = URB_ERROR;
 80015fa:	687a      	ldr	r2, [r7, #4]
 80015fc:	697b      	ldr	r3, [r7, #20]
 80015fe:	212c      	movs	r1, #44	; 0x2c
 8001600:	fb01 f303 	mul.w	r3, r1, r3
 8001604:	4413      	add	r3, r2
 8001606:	3360      	adds	r3, #96	; 0x60
 8001608:	2204      	movs	r2, #4
 800160a:	701a      	strb	r2, [r3, #0]
 800160c:	e021      	b.n	8001652 <HCD_HC_OUT_IRQHandler+0x69c>
        hhcd->hc[ch_num].urb_state = URB_NOTREADY;
 800160e:	687a      	ldr	r2, [r7, #4]
 8001610:	697b      	ldr	r3, [r7, #20]
 8001612:	212c      	movs	r1, #44	; 0x2c
 8001614:	fb01 f303 	mul.w	r3, r1, r3
 8001618:	4413      	add	r3, r2
 800161a:	3360      	adds	r3, #96	; 0x60
 800161c:	2202      	movs	r2, #2
 800161e:	701a      	strb	r2, [r3, #0]
        tmpreg = USBx_HC(ch_num)->HCCHAR;
 8001620:	697b      	ldr	r3, [r7, #20]
 8001622:	015a      	lsls	r2, r3, #5
 8001624:	69bb      	ldr	r3, [r7, #24]
 8001626:	4413      	add	r3, r2
 8001628:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 800162c:	681b      	ldr	r3, [r3, #0]
 800162e:	613b      	str	r3, [r7, #16]
        tmpreg &= ~USB_OTG_HCCHAR_CHDIS;
 8001630:	693b      	ldr	r3, [r7, #16]
 8001632:	f023 4380 	bic.w	r3, r3, #1073741824	; 0x40000000
 8001636:	613b      	str	r3, [r7, #16]
        tmpreg |= USB_OTG_HCCHAR_CHENA;
 8001638:	693b      	ldr	r3, [r7, #16]
 800163a:	f043 4300 	orr.w	r3, r3, #2147483648	; 0x80000000
 800163e:	613b      	str	r3, [r7, #16]
        USBx_HC(ch_num)->HCCHAR = tmpreg;
 8001640:	697b      	ldr	r3, [r7, #20]
 8001642:	015a      	lsls	r2, r3, #5
 8001644:	69bb      	ldr	r3, [r7, #24]
 8001646:	4413      	add	r3, r2
 8001648:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 800164c:	461a      	mov	r2, r3
 800164e:	693b      	ldr	r3, [r7, #16]
 8001650:	6013      	str	r3, [r2, #0]
    __HAL_HCD_CLEAR_HC_INT(ch_num, USB_OTG_HCINT_CHH);
 8001652:	697b      	ldr	r3, [r7, #20]
 8001654:	015a      	lsls	r2, r3, #5
 8001656:	69bb      	ldr	r3, [r7, #24]
 8001658:	4413      	add	r3, r2
 800165a:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 800165e:	461a      	mov	r2, r3
 8001660:	2302      	movs	r3, #2
 8001662:	6093      	str	r3, [r2, #8]
    HAL_HCD_HC_NotifyURBChange_Callback(hhcd, (uint8_t)ch_num, hhcd->hc[ch_num].urb_state);
 8001664:	697b      	ldr	r3, [r7, #20]
 8001666:	b2d9      	uxtb	r1, r3
 8001668:	687a      	ldr	r2, [r7, #4]
 800166a:	697b      	ldr	r3, [r7, #20]
 800166c:	202c      	movs	r0, #44	; 0x2c
 800166e:	fb00 f303 	mul.w	r3, r0, r3
 8001672:	4413      	add	r3, r2
 8001674:	3360      	adds	r3, #96	; 0x60
 8001676:	781b      	ldrb	r3, [r3, #0]
 8001678:	461a      	mov	r2, r3
 800167a:	6878      	ldr	r0, [r7, #4]
 800167c:	f000 fceb 	bl	8002056 <HAL_HCD_HC_NotifyURBChange_Callback>
}
 8001680:	bf00      	nop
 8001682:	3720      	adds	r7, #32
 8001684:	46bd      	mov	sp, r7
 8001686:	bd80      	pop	{r7, pc}

08001688 <HCD_RXQLVL_IRQHandler>:
  * @brief  Handle Rx Queue Level interrupt requests.
  * @param  hhcd HCD handle
  * @retval none
  */
static void HCD_RXQLVL_IRQHandler(HCD_HandleTypeDef *hhcd)
{
 8001688:	b580      	push	{r7, lr}
 800168a:	b08a      	sub	sp, #40	; 0x28
 800168c:	af00      	add	r7, sp, #0
 800168e:	6078      	str	r0, [r7, #4]
  USB_OTG_GlobalTypeDef *USBx = hhcd->Instance;
 8001690:	687b      	ldr	r3, [r7, #4]
 8001692:	681b      	ldr	r3, [r3, #0]
 8001694:	627b      	str	r3, [r7, #36]	; 0x24
  uint32_t USBx_BASE = (uint32_t)USBx;
 8001696:	6a7b      	ldr	r3, [r7, #36]	; 0x24
 8001698:	623b      	str	r3, [r7, #32]
  uint32_t GrxstspReg;
  uint32_t xferSizePktCnt;
  uint32_t tmpreg;
  uint32_t ch_num;

  GrxstspReg = hhcd->Instance->GRXSTSP;
 800169a:	687b      	ldr	r3, [r7, #4]
 800169c:	681b      	ldr	r3, [r3, #0]
 800169e:	6a1b      	ldr	r3, [r3, #32]
 80016a0:	61fb      	str	r3, [r7, #28]
  ch_num = GrxstspReg & USB_OTG_GRXSTSP_EPNUM;
 80016a2:	69fb      	ldr	r3, [r7, #28]
 80016a4:	f003 030f 	and.w	r3, r3, #15
 80016a8:	61bb      	str	r3, [r7, #24]
  pktsts = (GrxstspReg & USB_OTG_GRXSTSP_PKTSTS) >> 17;
 80016aa:	69fb      	ldr	r3, [r7, #28]
 80016ac:	0c5b      	lsrs	r3, r3, #17
 80016ae:	f003 030f 	and.w	r3, r3, #15
 80016b2:	617b      	str	r3, [r7, #20]
  pktcnt = (GrxstspReg & USB_OTG_GRXSTSP_BCNT) >> 4;
 80016b4:	69fb      	ldr	r3, [r7, #28]
 80016b6:	091b      	lsrs	r3, r3, #4
 80016b8:	f3c3 030a 	ubfx	r3, r3, #0, #11
 80016bc:	613b      	str	r3, [r7, #16]

  switch (pktsts)
 80016be:	697b      	ldr	r3, [r7, #20]
 80016c0:	2b02      	cmp	r3, #2
 80016c2:	d004      	beq.n	80016ce <HCD_RXQLVL_IRQHandler+0x46>
 80016c4:	697b      	ldr	r3, [r7, #20]
 80016c6:	2b05      	cmp	r3, #5
 80016c8:	f000 80a9 	beq.w	800181e <HCD_RXQLVL_IRQHandler+0x196>
      break;

    case GRXSTS_PKTSTS_IN_XFER_COMP:
    case GRXSTS_PKTSTS_CH_HALTED:
    default:
      break;
 80016cc:	e0aa      	b.n	8001824 <HCD_RXQLVL_IRQHandler+0x19c>
      if ((pktcnt > 0U) && (hhcd->hc[ch_num].xfer_buff != (void *)0))
 80016ce:	693b      	ldr	r3, [r7, #16]
 80016d0:	2b00      	cmp	r3, #0
 80016d2:	f000 80a6 	beq.w	8001822 <HCD_RXQLVL_IRQHandler+0x19a>
 80016d6:	687a      	ldr	r2, [r7, #4]
 80016d8:	69bb      	ldr	r3, [r7, #24]
 80016da:	212c      	movs	r1, #44	; 0x2c
 80016dc:	fb01 f303 	mul.w	r3, r1, r3
 80016e0:	4413      	add	r3, r2
 80016e2:	3344      	adds	r3, #68	; 0x44
 80016e4:	681b      	ldr	r3, [r3, #0]
 80016e6:	2b00      	cmp	r3, #0
 80016e8:	f000 809b 	beq.w	8001822 <HCD_RXQLVL_IRQHandler+0x19a>
        if ((hhcd->hc[ch_num].xfer_count + pktcnt) <= hhcd->hc[ch_num].xfer_len)
 80016ec:	687a      	ldr	r2, [r7, #4]
 80016ee:	69bb      	ldr	r3, [r7, #24]
 80016f0:	212c      	movs	r1, #44	; 0x2c
 80016f2:	fb01 f303 	mul.w	r3, r1, r3
 80016f6:	4413      	add	r3, r2
 80016f8:	3350      	adds	r3, #80	; 0x50
 80016fa:	681a      	ldr	r2, [r3, #0]
 80016fc:	693b      	ldr	r3, [r7, #16]
 80016fe:	441a      	add	r2, r3
 8001700:	6879      	ldr	r1, [r7, #4]
 8001702:	69bb      	ldr	r3, [r7, #24]
 8001704:	202c      	movs	r0, #44	; 0x2c
 8001706:	fb00 f303 	mul.w	r3, r0, r3
 800170a:	440b      	add	r3, r1
 800170c:	334c      	adds	r3, #76	; 0x4c
 800170e:	681b      	ldr	r3, [r3, #0]
 8001710:	429a      	cmp	r2, r3
 8001712:	d87a      	bhi.n	800180a <HCD_RXQLVL_IRQHandler+0x182>
          (void)USB_ReadPacket(hhcd->Instance,
 8001714:	687b      	ldr	r3, [r7, #4]
 8001716:	6818      	ldr	r0, [r3, #0]
 8001718:	687a      	ldr	r2, [r7, #4]
 800171a:	69bb      	ldr	r3, [r7, #24]
 800171c:	212c      	movs	r1, #44	; 0x2c
 800171e:	fb01 f303 	mul.w	r3, r1, r3
 8001722:	4413      	add	r3, r2
 8001724:	3344      	adds	r3, #68	; 0x44
 8001726:	681b      	ldr	r3, [r3, #0]
 8001728:	693a      	ldr	r2, [r7, #16]
 800172a:	b292      	uxth	r2, r2
 800172c:	4619      	mov	r1, r3
 800172e:	f000 f977 	bl	8001a20 <USB_ReadPacket>
          hhcd->hc[ch_num].xfer_buff += pktcnt;
 8001732:	687a      	ldr	r2, [r7, #4]
 8001734:	69bb      	ldr	r3, [r7, #24]
 8001736:	212c      	movs	r1, #44	; 0x2c
 8001738:	fb01 f303 	mul.w	r3, r1, r3
 800173c:	4413      	add	r3, r2
 800173e:	3344      	adds	r3, #68	; 0x44
 8001740:	681a      	ldr	r2, [r3, #0]
 8001742:	693b      	ldr	r3, [r7, #16]
 8001744:	441a      	add	r2, r3
 8001746:	6879      	ldr	r1, [r7, #4]
 8001748:	69bb      	ldr	r3, [r7, #24]
 800174a:	202c      	movs	r0, #44	; 0x2c
 800174c:	fb00 f303 	mul.w	r3, r0, r3
 8001750:	440b      	add	r3, r1
 8001752:	3344      	adds	r3, #68	; 0x44
 8001754:	601a      	str	r2, [r3, #0]
          hhcd->hc[ch_num].xfer_count += pktcnt;
 8001756:	687a      	ldr	r2, [r7, #4]
 8001758:	69bb      	ldr	r3, [r7, #24]
 800175a:	212c      	movs	r1, #44	; 0x2c
 800175c:	fb01 f303 	mul.w	r3, r1, r3
 8001760:	4413      	add	r3, r2
 8001762:	3350      	adds	r3, #80	; 0x50
 8001764:	681a      	ldr	r2, [r3, #0]
 8001766:	693b      	ldr	r3, [r7, #16]
 8001768:	441a      	add	r2, r3
 800176a:	6879      	ldr	r1, [r7, #4]
 800176c:	69bb      	ldr	r3, [r7, #24]
 800176e:	202c      	movs	r0, #44	; 0x2c
 8001770:	fb00 f303 	mul.w	r3, r0, r3
 8001774:	440b      	add	r3, r1
 8001776:	3350      	adds	r3, #80	; 0x50
 8001778:	601a      	str	r2, [r3, #0]
          xferSizePktCnt = (USBx_HC(ch_num)->HCTSIZ & USB_OTG_HCTSIZ_PKTCNT) >> 19;
 800177a:	69bb      	ldr	r3, [r7, #24]
 800177c:	015a      	lsls	r2, r3, #5
 800177e:	6a3b      	ldr	r3, [r7, #32]
 8001780:	4413      	add	r3, r2
 8001782:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 8001786:	691b      	ldr	r3, [r3, #16]
 8001788:	0cdb      	lsrs	r3, r3, #19
 800178a:	f3c3 0309 	ubfx	r3, r3, #0, #10
 800178e:	60fb      	str	r3, [r7, #12]
          if ((hhcd->hc[ch_num].max_packet == pktcnt) && (xferSizePktCnt > 0U))
 8001790:	687a      	ldr	r2, [r7, #4]
 8001792:	69bb      	ldr	r3, [r7, #24]
 8001794:	212c      	movs	r1, #44	; 0x2c
 8001796:	fb01 f303 	mul.w	r3, r1, r3
 800179a:	4413      	add	r3, r2
 800179c:	3340      	adds	r3, #64	; 0x40
 800179e:	881b      	ldrh	r3, [r3, #0]
 80017a0:	461a      	mov	r2, r3
 80017a2:	693b      	ldr	r3, [r7, #16]
 80017a4:	4293      	cmp	r3, r2
 80017a6:	d13c      	bne.n	8001822 <HCD_RXQLVL_IRQHandler+0x19a>
 80017a8:	68fb      	ldr	r3, [r7, #12]
 80017aa:	2b00      	cmp	r3, #0
 80017ac:	d039      	beq.n	8001822 <HCD_RXQLVL_IRQHandler+0x19a>
            tmpreg = USBx_HC(ch_num)->HCCHAR;
 80017ae:	69bb      	ldr	r3, [r7, #24]
 80017b0:	015a      	lsls	r2, r3, #5
 80017b2:	6a3b      	ldr	r3, [r7, #32]
 80017b4:	4413      	add	r3, r2
 80017b6:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 80017ba:	681b      	ldr	r3, [r3, #0]
 80017bc:	60bb      	str	r3, [r7, #8]
            tmpreg &= ~USB_OTG_HCCHAR_CHDIS;
 80017be:	68bb      	ldr	r3, [r7, #8]
 80017c0:	f023 4380 	bic.w	r3, r3, #1073741824	; 0x40000000
 80017c4:	60bb      	str	r3, [r7, #8]
            tmpreg |= USB_OTG_HCCHAR_CHENA;
 80017c6:	68bb      	ldr	r3, [r7, #8]
 80017c8:	f043 4300 	orr.w	r3, r3, #2147483648	; 0x80000000
 80017cc:	60bb      	str	r3, [r7, #8]
            USBx_HC(ch_num)->HCCHAR = tmpreg;
 80017ce:	69bb      	ldr	r3, [r7, #24]
 80017d0:	015a      	lsls	r2, r3, #5
 80017d2:	6a3b      	ldr	r3, [r7, #32]
 80017d4:	4413      	add	r3, r2
 80017d6:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 80017da:	461a      	mov	r2, r3
 80017dc:	68bb      	ldr	r3, [r7, #8]
 80017de:	6013      	str	r3, [r2, #0]
            hhcd->hc[ch_num].toggle_in ^= 1U;
 80017e0:	687a      	ldr	r2, [r7, #4]
 80017e2:	69bb      	ldr	r3, [r7, #24]
 80017e4:	212c      	movs	r1, #44	; 0x2c
 80017e6:	fb01 f303 	mul.w	r3, r1, r3
 80017ea:	4413      	add	r3, r2
 80017ec:	3354      	adds	r3, #84	; 0x54
 80017ee:	781b      	ldrb	r3, [r3, #0]
 80017f0:	f083 0301 	eor.w	r3, r3, #1
 80017f4:	b2d8      	uxtb	r0, r3
 80017f6:	687a      	ldr	r2, [r7, #4]
 80017f8:	69bb      	ldr	r3, [r7, #24]
 80017fa:	212c      	movs	r1, #44	; 0x2c
 80017fc:	fb01 f303 	mul.w	r3, r1, r3
 8001800:	4413      	add	r3, r2
 8001802:	3354      	adds	r3, #84	; 0x54
 8001804:	4602      	mov	r2, r0
 8001806:	701a      	strb	r2, [r3, #0]
      break;
 8001808:	e00b      	b.n	8001822 <HCD_RXQLVL_IRQHandler+0x19a>
          hhcd->hc[ch_num].urb_state = URB_ERROR;
 800180a:	687a      	ldr	r2, [r7, #4]
 800180c:	69bb      	ldr	r3, [r7, #24]
 800180e:	212c      	movs	r1, #44	; 0x2c
 8001810:	fb01 f303 	mul.w	r3, r1, r3
 8001814:	4413      	add	r3, r2
 8001816:	3360      	adds	r3, #96	; 0x60
 8001818:	2204      	movs	r2, #4
 800181a:	701a      	strb	r2, [r3, #0]
      break;
 800181c:	e001      	b.n	8001822 <HCD_RXQLVL_IRQHandler+0x19a>
      break;
 800181e:	bf00      	nop
 8001820:	e000      	b.n	8001824 <HCD_RXQLVL_IRQHandler+0x19c>
      break;
 8001822:	bf00      	nop
  }
}
 8001824:	bf00      	nop
 8001826:	3728      	adds	r7, #40	; 0x28
 8001828:	46bd      	mov	sp, r7
 800182a:	bd80      	pop	{r7, pc}

0800182c <HCD_Port_IRQHandler>:
  * @brief  Handle Host Port interrupt requests.
  * @param  hhcd HCD handle
  * @retval None
  */
static void HCD_Port_IRQHandler(HCD_HandleTypeDef *hhcd)
{
 800182c:	b580      	push	{r7, lr}
 800182e:	b086      	sub	sp, #24
 8001830:	af00      	add	r7, sp, #0
 8001832:	6078      	str	r0, [r7, #4]
  USB_OTG_GlobalTypeDef *USBx = hhcd->Instance;
 8001834:	687b      	ldr	r3, [r7, #4]
 8001836:	681b      	ldr	r3, [r3, #0]
 8001838:	617b      	str	r3, [r7, #20]
  uint32_t USBx_BASE = (uint32_t)USBx;
 800183a:	697b      	ldr	r3, [r7, #20]
 800183c:	613b      	str	r3, [r7, #16]
  __IO uint32_t hprt0;
  __IO uint32_t hprt0_dup;

  /* Handle Host Port Interrupts */
  hprt0 = USBx_HPRT0;
 800183e:	693b      	ldr	r3, [r7, #16]
 8001840:	f503 6388 	add.w	r3, r3, #1088	; 0x440
 8001844:	681b      	ldr	r3, [r3, #0]
 8001846:	60fb      	str	r3, [r7, #12]
  hprt0_dup = USBx_HPRT0;
 8001848:	693b      	ldr	r3, [r7, #16]
 800184a:	f503 6388 	add.w	r3, r3, #1088	; 0x440
 800184e:	681b      	ldr	r3, [r3, #0]
 8001850:	60bb      	str	r3, [r7, #8]

  hprt0_dup &= ~(USB_OTG_HPRT_PENA | USB_OTG_HPRT_PCDET | \
 8001852:	68bb      	ldr	r3, [r7, #8]
 8001854:	f023 032e 	bic.w	r3, r3, #46	; 0x2e
 8001858:	60bb      	str	r3, [r7, #8]
                 USB_OTG_HPRT_PENCHNG | USB_OTG_HPRT_POCCHNG);

  /* Check whether Port Connect detected */
  if ((hprt0 & USB_OTG_HPRT_PCDET) == USB_OTG_HPRT_PCDET)
 800185a:	68fb      	ldr	r3, [r7, #12]
 800185c:	f003 0302 	and.w	r3, r3, #2
 8001860:	2b02      	cmp	r3, #2
 8001862:	d10b      	bne.n	800187c <HCD_Port_IRQHandler+0x50>
  {
    if ((hprt0 & USB_OTG_HPRT_PCSTS) == USB_OTG_HPRT_PCSTS)
 8001864:	68fb      	ldr	r3, [r7, #12]
 8001866:	f003 0301 	and.w	r3, r3, #1
 800186a:	2b01      	cmp	r3, #1
 800186c:	d102      	bne.n	8001874 <HCD_Port_IRQHandler+0x48>
    {
#if (USE_HAL_HCD_REGISTER_CALLBACKS == 1U)
      hhcd->ConnectCallback(hhcd);
#else
      HAL_HCD_Connect_Callback(hhcd);
 800186e:	6878      	ldr	r0, [r7, #4]
 8001870:	f000 fbd5 	bl	800201e <HAL_HCD_Connect_Callback>
#endif /* USE_HAL_HCD_REGISTER_CALLBACKS */
    }
    hprt0_dup |= USB_OTG_HPRT_PCDET;
 8001874:	68bb      	ldr	r3, [r7, #8]
 8001876:	f043 0302 	orr.w	r3, r3, #2
 800187a:	60bb      	str	r3, [r7, #8]
  }

  /* Check whether Port Enable Changed */
  if ((hprt0 & USB_OTG_HPRT_PENCHNG) == USB_OTG_HPRT_PENCHNG)
 800187c:	68fb      	ldr	r3, [r7, #12]
 800187e:	f003 0308 	and.w	r3, r3, #8
 8001882:	2b08      	cmp	r3, #8
 8001884:	d132      	bne.n	80018ec <HCD_Port_IRQHandler+0xc0>
  {
    hprt0_dup |= USB_OTG_HPRT_PENCHNG;
 8001886:	68bb      	ldr	r3, [r7, #8]
 8001888:	f043 0308 	orr.w	r3, r3, #8
 800188c:	60bb      	str	r3, [r7, #8]

    if ((hprt0 & USB_OTG_HPRT_PENA) == USB_OTG_HPRT_PENA)
 800188e:	68fb      	ldr	r3, [r7, #12]
 8001890:	f003 0304 	and.w	r3, r3, #4
 8001894:	2b04      	cmp	r3, #4
 8001896:	d126      	bne.n	80018e6 <HCD_Port_IRQHandler+0xba>
    {
      if (hhcd->Init.phy_itface  == USB_OTG_EMBEDDED_PHY)
 8001898:	687b      	ldr	r3, [r7, #4]
 800189a:	699b      	ldr	r3, [r3, #24]
 800189c:	2b02      	cmp	r3, #2
 800189e:	d113      	bne.n	80018c8 <HCD_Port_IRQHandler+0x9c>
      {
        if ((hprt0 & USB_OTG_HPRT_PSPD) == (HPRT0_PRTSPD_LOW_SPEED << 17))
 80018a0:	68fb      	ldr	r3, [r7, #12]
 80018a2:	f403 23c0 	and.w	r3, r3, #393216	; 0x60000
 80018a6:	f5b3 2f80 	cmp.w	r3, #262144	; 0x40000
 80018aa:	d106      	bne.n	80018ba <HCD_Port_IRQHandler+0x8e>
        {
          (void)USB_InitFSLSPClkSel(hhcd->Instance, HCFG_6_MHZ);
 80018ac:	687b      	ldr	r3, [r7, #4]
 80018ae:	681b      	ldr	r3, [r3, #0]
 80018b0:	2102      	movs	r1, #2
 80018b2:	4618      	mov	r0, r3
 80018b4:	f000 f92d 	bl	8001b12 <USB_InitFSLSPClkSel>
 80018b8:	e011      	b.n	80018de <HCD_Port_IRQHandler+0xb2>
        }
        else
        {
          (void)USB_InitFSLSPClkSel(hhcd->Instance, HCFG_48_MHZ);
 80018ba:	687b      	ldr	r3, [r7, #4]
 80018bc:	681b      	ldr	r3, [r3, #0]
 80018be:	2101      	movs	r1, #1
 80018c0:	4618      	mov	r0, r3
 80018c2:	f000 f926 	bl	8001b12 <USB_InitFSLSPClkSel>
 80018c6:	e00a      	b.n	80018de <HCD_Port_IRQHandler+0xb2>
        }
      }
      else
      {
        if (hhcd->Init.speed == HCD_SPEED_FULL)
 80018c8:	687b      	ldr	r3, [r7, #4]
 80018ca:	68db      	ldr	r3, [r3, #12]
 80018cc:	2b01      	cmp	r3, #1
 80018ce:	d106      	bne.n	80018de <HCD_Port_IRQHandler+0xb2>
        {
          USBx_HOST->HFIR = 60000U;
 80018d0:	693b      	ldr	r3, [r7, #16]
 80018d2:	f503 6380 	add.w	r3, r3, #1024	; 0x400
 80018d6:	461a      	mov	r2, r3
 80018d8:	f64e 2360 	movw	r3, #60000	; 0xea60
 80018dc:	6053      	str	r3, [r2, #4]
        }
      }
#if (USE_HAL_HCD_REGISTER_CALLBACKS == 1U)
      hhcd->PortEnabledCallback(hhcd);
#else
      HAL_HCD_PortEnabled_Callback(hhcd);
 80018de:	6878      	ldr	r0, [r7, #4]
 80018e0:	f000 fbc7 	bl	8002072 <HAL_HCD_PortEnabled_Callback>
 80018e4:	e002      	b.n	80018ec <HCD_Port_IRQHandler+0xc0>
    else
    {
#if (USE_HAL_HCD_REGISTER_CALLBACKS == 1U)
      hhcd->PortDisabledCallback(hhcd);
#else
      HAL_HCD_PortDisabled_Callback(hhcd);
 80018e6:	6878      	ldr	r0, [r7, #4]
 80018e8:	f000 fbd1 	bl	800208e <HAL_HCD_PortDisabled_Callback>
#endif /* USE_HAL_HCD_REGISTER_CALLBACKS */
    }
  }

  /* Check for an overcurrent */
  if ((hprt0 & USB_OTG_HPRT_POCCHNG) == USB_OTG_HPRT_POCCHNG)
 80018ec:	68fb      	ldr	r3, [r7, #12]
 80018ee:	f003 0320 	and.w	r3, r3, #32
 80018f2:	2b20      	cmp	r3, #32
 80018f4:	d103      	bne.n	80018fe <HCD_Port_IRQHandler+0xd2>
  {
    hprt0_dup |= USB_OTG_HPRT_POCCHNG;
 80018f6:	68bb      	ldr	r3, [r7, #8]
 80018f8:	f043 0320 	orr.w	r3, r3, #32
 80018fc:	60bb      	str	r3, [r7, #8]
  }

  /* Clear Port Interrupts */
  USBx_HPRT0 = hprt0_dup;
 80018fe:	693b      	ldr	r3, [r7, #16]
 8001900:	f503 6388 	add.w	r3, r3, #1088	; 0x440
 8001904:	461a      	mov	r2, r3
 8001906:	68bb      	ldr	r3, [r7, #8]
 8001908:	6013      	str	r3, [r2, #0]
}
 800190a:	bf00      	nop
 800190c:	3718      	adds	r7, #24
 800190e:	46bd      	mov	sp, r7
 8001910:	bd80      	pop	{r7, pc}

08001912 <USB_EnableGlobalInt>:
  *         Enables the controller's Global Int in the AHB Config reg
  * @param  USBx  Selected device
  * @retval HAL status
  */
HAL_StatusTypeDef USB_EnableGlobalInt(USB_OTG_GlobalTypeDef *USBx)
{
 8001912:	b480      	push	{r7}
 8001914:	b083      	sub	sp, #12
 8001916:	af00      	add	r7, sp, #0
 8001918:	6078      	str	r0, [r7, #4]
  USBx->GAHBCFG |= USB_OTG_GAHBCFG_GINT;
 800191a:	687b      	ldr	r3, [r7, #4]
 800191c:	689b      	ldr	r3, [r3, #8]
 800191e:	f043 0201 	orr.w	r2, r3, #1
 8001922:	687b      	ldr	r3, [r7, #4]
 8001924:	609a      	str	r2, [r3, #8]
  return HAL_OK;
 8001926:	2300      	movs	r3, #0
}
 8001928:	4618      	mov	r0, r3
 800192a:	370c      	adds	r7, #12
 800192c:	46bd      	mov	sp, r7
 800192e:	f85d 7b04 	ldr.w	r7, [sp], #4
 8001932:	4770      	bx	lr

08001934 <USB_DisableGlobalInt>:
  *         Disable the controller's Global Int in the AHB Config reg
  * @param  USBx  Selected device
  * @retval HAL status
  */
HAL_StatusTypeDef USB_DisableGlobalInt(USB_OTG_GlobalTypeDef *USBx)
{
 8001934:	b480      	push	{r7}
 8001936:	b083      	sub	sp, #12
 8001938:	af00      	add	r7, sp, #0
 800193a:	6078      	str	r0, [r7, #4]
  USBx->GAHBCFG &= ~USB_OTG_GAHBCFG_GINT;
 800193c:	687b      	ldr	r3, [r7, #4]
 800193e:	689b      	ldr	r3, [r3, #8]
 8001940:	f023 0201 	bic.w	r2, r3, #1
 8001944:	687b      	ldr	r3, [r7, #4]
 8001946:	609a      	str	r2, [r3, #8]
  return HAL_OK;
 8001948:	2300      	movs	r3, #0
}
 800194a:	4618      	mov	r0, r3
 800194c:	370c      	adds	r7, #12
 800194e:	46bd      	mov	sp, r7
 8001950:	f85d 7b04 	ldr.w	r7, [sp], #4
 8001954:	4770      	bx	lr
	...

08001958 <USB_FlushTxFifo>:
  *         This parameter can be a value from 1 to 15
            15 means Flush all Tx FIFOs
  * @retval HAL status
  */
HAL_StatusTypeDef USB_FlushTxFifo(USB_OTG_GlobalTypeDef *USBx, uint32_t num)
{
 8001958:	b480      	push	{r7}
 800195a:	b085      	sub	sp, #20
 800195c:	af00      	add	r7, sp, #0
 800195e:	6078      	str	r0, [r7, #4]
 8001960:	6039      	str	r1, [r7, #0]
  __IO uint32_t count = 0U;
 8001962:	2300      	movs	r3, #0
 8001964:	60fb      	str	r3, [r7, #12]

  /* Wait for AHB master IDLE state. */
  do
  {
    count++;
 8001966:	68fb      	ldr	r3, [r7, #12]
 8001968:	3301      	adds	r3, #1
 800196a:	60fb      	str	r3, [r7, #12]

    if (count > 200000U)
 800196c:	68fb      	ldr	r3, [r7, #12]
 800196e:	4a13      	ldr	r2, [pc, #76]	; (80019bc <USB_FlushTxFifo+0x64>)
 8001970:	4293      	cmp	r3, r2
 8001972:	d901      	bls.n	8001978 <USB_FlushTxFifo+0x20>
    {
      return HAL_TIMEOUT;
 8001974:	2303      	movs	r3, #3
 8001976:	e01b      	b.n	80019b0 <USB_FlushTxFifo+0x58>
    }
  } while ((USBx->GRSTCTL & USB_OTG_GRSTCTL_AHBIDL) == 0U);
 8001978:	687b      	ldr	r3, [r7, #4]
 800197a:	691b      	ldr	r3, [r3, #16]
 800197c:	2b00      	cmp	r3, #0
 800197e:	daf2      	bge.n	8001966 <USB_FlushTxFifo+0xe>

  /* Flush TX Fifo */
  count = 0U;
 8001980:	2300      	movs	r3, #0
 8001982:	60fb      	str	r3, [r7, #12]
  USBx->GRSTCTL = (USB_OTG_GRSTCTL_TXFFLSH | (num << 6));
 8001984:	683b      	ldr	r3, [r7, #0]
 8001986:	019b      	lsls	r3, r3, #6
 8001988:	f043 0220 	orr.w	r2, r3, #32
 800198c:	687b      	ldr	r3, [r7, #4]
 800198e:	611a      	str	r2, [r3, #16]

  do
  {
    count++;
 8001990:	68fb      	ldr	r3, [r7, #12]
 8001992:	3301      	adds	r3, #1
 8001994:	60fb      	str	r3, [r7, #12]

    if (count > 200000U)
 8001996:	68fb      	ldr	r3, [r7, #12]
 8001998:	4a08      	ldr	r2, [pc, #32]	; (80019bc <USB_FlushTxFifo+0x64>)
 800199a:	4293      	cmp	r3, r2
 800199c:	d901      	bls.n	80019a2 <USB_FlushTxFifo+0x4a>
    {
      return HAL_TIMEOUT;
 800199e:	2303      	movs	r3, #3
 80019a0:	e006      	b.n	80019b0 <USB_FlushTxFifo+0x58>
    }
  } while ((USBx->GRSTCTL & USB_OTG_GRSTCTL_TXFFLSH) == USB_OTG_GRSTCTL_TXFFLSH);
 80019a2:	687b      	ldr	r3, [r7, #4]
 80019a4:	691b      	ldr	r3, [r3, #16]
 80019a6:	f003 0320 	and.w	r3, r3, #32
 80019aa:	2b20      	cmp	r3, #32
 80019ac:	d0f0      	beq.n	8001990 <USB_FlushTxFifo+0x38>

  return HAL_OK;
 80019ae:	2300      	movs	r3, #0
}
 80019b0:	4618      	mov	r0, r3
 80019b2:	3714      	adds	r7, #20
 80019b4:	46bd      	mov	sp, r7
 80019b6:	f85d 7b04 	ldr.w	r7, [sp], #4
 80019ba:	4770      	bx	lr
 80019bc:	00030d40 	.word	0x00030d40

080019c0 <USB_FlushRxFifo>:
  * @brief  USB_FlushRxFifo  Flush Rx FIFO
  * @param  USBx  Selected device
  * @retval HAL status
  */
HAL_StatusTypeDef USB_FlushRxFifo(USB_OTG_GlobalTypeDef *USBx)
{
 80019c0:	b480      	push	{r7}
 80019c2:	b085      	sub	sp, #20
 80019c4:	af00      	add	r7, sp, #0
 80019c6:	6078      	str	r0, [r7, #4]
  __IO uint32_t count = 0U;
 80019c8:	2300      	movs	r3, #0
 80019ca:	60fb      	str	r3, [r7, #12]

  /* Wait for AHB master IDLE state. */
  do
  {
    count++;
 80019cc:	68fb      	ldr	r3, [r7, #12]
 80019ce:	3301      	adds	r3, #1
 80019d0:	60fb      	str	r3, [r7, #12]

    if (count > 200000U)
 80019d2:	68fb      	ldr	r3, [r7, #12]
 80019d4:	4a11      	ldr	r2, [pc, #68]	; (8001a1c <USB_FlushRxFifo+0x5c>)
 80019d6:	4293      	cmp	r3, r2
 80019d8:	d901      	bls.n	80019de <USB_FlushRxFifo+0x1e>
    {
      return HAL_TIMEOUT;
 80019da:	2303      	movs	r3, #3
 80019dc:	e018      	b.n	8001a10 <USB_FlushRxFifo+0x50>
    }
  } while ((USBx->GRSTCTL & USB_OTG_GRSTCTL_AHBIDL) == 0U);
 80019de:	687b      	ldr	r3, [r7, #4]
 80019e0:	691b      	ldr	r3, [r3, #16]
 80019e2:	2b00      	cmp	r3, #0
 80019e4:	daf2      	bge.n	80019cc <USB_FlushRxFifo+0xc>

  /* Flush RX Fifo */
  count = 0U;
 80019e6:	2300      	movs	r3, #0
 80019e8:	60fb      	str	r3, [r7, #12]
  USBx->GRSTCTL = USB_OTG_GRSTCTL_RXFFLSH;
 80019ea:	687b      	ldr	r3, [r7, #4]
 80019ec:	2210      	movs	r2, #16
 80019ee:	611a      	str	r2, [r3, #16]

  do
  {
    count++;
 80019f0:	68fb      	ldr	r3, [r7, #12]
 80019f2:	3301      	adds	r3, #1
 80019f4:	60fb      	str	r3, [r7, #12]

    if (count > 200000U)
 80019f6:	68fb      	ldr	r3, [r7, #12]
 80019f8:	4a08      	ldr	r2, [pc, #32]	; (8001a1c <USB_FlushRxFifo+0x5c>)
 80019fa:	4293      	cmp	r3, r2
 80019fc:	d901      	bls.n	8001a02 <USB_FlushRxFifo+0x42>
    {
      return HAL_TIMEOUT;
 80019fe:	2303      	movs	r3, #3
 8001a00:	e006      	b.n	8001a10 <USB_FlushRxFifo+0x50>
    }
  } while ((USBx->GRSTCTL & USB_OTG_GRSTCTL_RXFFLSH) == USB_OTG_GRSTCTL_RXFFLSH);
 8001a02:	687b      	ldr	r3, [r7, #4]
 8001a04:	691b      	ldr	r3, [r3, #16]
 8001a06:	f003 0310 	and.w	r3, r3, #16
 8001a0a:	2b10      	cmp	r3, #16
 8001a0c:	d0f0      	beq.n	80019f0 <USB_FlushRxFifo+0x30>

  return HAL_OK;
 8001a0e:	2300      	movs	r3, #0
}
 8001a10:	4618      	mov	r0, r3
 8001a12:	3714      	adds	r7, #20
 8001a14:	46bd      	mov	sp, r7
 8001a16:	f85d 7b04 	ldr.w	r7, [sp], #4
 8001a1a:	4770      	bx	lr
 8001a1c:	00030d40 	.word	0x00030d40

08001a20 <USB_ReadPacket>:
  * @param  dest  source pointer
  * @param  len  Number of bytes to read
  * @retval pointer to destination buffer
  */
void *USB_ReadPacket(USB_OTG_GlobalTypeDef *USBx, uint8_t *dest, uint16_t len)
{
 8001a20:	b480      	push	{r7}
 8001a22:	b08b      	sub	sp, #44	; 0x2c
 8001a24:	af00      	add	r7, sp, #0
 8001a26:	60f8      	str	r0, [r7, #12]
 8001a28:	60b9      	str	r1, [r7, #8]
 8001a2a:	4613      	mov	r3, r2
 8001a2c:	80fb      	strh	r3, [r7, #6]
  uint32_t USBx_BASE = (uint32_t)USBx;
 8001a2e:	68fb      	ldr	r3, [r7, #12]
 8001a30:	61bb      	str	r3, [r7, #24]
  uint8_t *pDest = dest;
 8001a32:	68bb      	ldr	r3, [r7, #8]
 8001a34:	627b      	str	r3, [r7, #36]	; 0x24
  uint32_t pData;
  uint32_t i;
  uint32_t count32b = (uint32_t)len >> 2U;
 8001a36:	88fb      	ldrh	r3, [r7, #6]
 8001a38:	089b      	lsrs	r3, r3, #2
 8001a3a:	b29b      	uxth	r3, r3
 8001a3c:	617b      	str	r3, [r7, #20]
  uint16_t remaining_bytes = len % 4U;
 8001a3e:	88fb      	ldrh	r3, [r7, #6]
 8001a40:	f003 0303 	and.w	r3, r3, #3
 8001a44:	83fb      	strh	r3, [r7, #30]

  for (i = 0U; i < count32b; i++)
 8001a46:	2300      	movs	r3, #0
 8001a48:	623b      	str	r3, [r7, #32]
 8001a4a:	e014      	b.n	8001a76 <USB_ReadPacket+0x56>
  {
    __UNALIGNED_UINT32_WRITE(pDest, USBx_DFIFO(0U));
 8001a4c:	69bb      	ldr	r3, [r7, #24]
 8001a4e:	f503 5380 	add.w	r3, r3, #4096	; 0x1000
 8001a52:	681a      	ldr	r2, [r3, #0]
 8001a54:	6a7b      	ldr	r3, [r7, #36]	; 0x24
 8001a56:	601a      	str	r2, [r3, #0]
    pDest++;
 8001a58:	6a7b      	ldr	r3, [r7, #36]	; 0x24
 8001a5a:	3301      	adds	r3, #1
 8001a5c:	627b      	str	r3, [r7, #36]	; 0x24
    pDest++;
 8001a5e:	6a7b      	ldr	r3, [r7, #36]	; 0x24
 8001a60:	3301      	adds	r3, #1
 8001a62:	627b      	str	r3, [r7, #36]	; 0x24
    pDest++;
 8001a64:	6a7b      	ldr	r3, [r7, #36]	; 0x24
 8001a66:	3301      	adds	r3, #1
 8001a68:	627b      	str	r3, [r7, #36]	; 0x24
    pDest++;
 8001a6a:	6a7b      	ldr	r3, [r7, #36]	; 0x24
 8001a6c:	3301      	adds	r3, #1
 8001a6e:	627b      	str	r3, [r7, #36]	; 0x24
  for (i = 0U; i < count32b; i++)
 8001a70:	6a3b      	ldr	r3, [r7, #32]
 8001a72:	3301      	adds	r3, #1
 8001a74:	623b      	str	r3, [r7, #32]
 8001a76:	6a3a      	ldr	r2, [r7, #32]
 8001a78:	697b      	ldr	r3, [r7, #20]
 8001a7a:	429a      	cmp	r2, r3
 8001a7c:	d3e6      	bcc.n	8001a4c <USB_ReadPacket+0x2c>
  }

  /* When Number of data is not word aligned, read the remaining byte */
  if (remaining_bytes != 0U)
 8001a7e:	8bfb      	ldrh	r3, [r7, #30]
 8001a80:	2b00      	cmp	r3, #0
 8001a82:	d01e      	beq.n	8001ac2 <USB_ReadPacket+0xa2>
  {
    i = 0U;
 8001a84:	2300      	movs	r3, #0
 8001a86:	623b      	str	r3, [r7, #32]
    __UNALIGNED_UINT32_WRITE(&pData, USBx_DFIFO(0U));
 8001a88:	69bb      	ldr	r3, [r7, #24]
 8001a8a:	f503 5380 	add.w	r3, r3, #4096	; 0x1000
 8001a8e:	461a      	mov	r2, r3
 8001a90:	f107 0310 	add.w	r3, r7, #16
 8001a94:	6812      	ldr	r2, [r2, #0]
 8001a96:	601a      	str	r2, [r3, #0]

    do
    {
      *(uint8_t *)pDest = (uint8_t)(pData >> (8U * (uint8_t)(i)));
 8001a98:	693a      	ldr	r2, [r7, #16]
 8001a9a:	6a3b      	ldr	r3, [r7, #32]
 8001a9c:	b2db      	uxtb	r3, r3
 8001a9e:	00db      	lsls	r3, r3, #3
 8001aa0:	fa22 f303 	lsr.w	r3, r2, r3
 8001aa4:	b2da      	uxtb	r2, r3
 8001aa6:	6a7b      	ldr	r3, [r7, #36]	; 0x24
 8001aa8:	701a      	strb	r2, [r3, #0]
      i++;
 8001aaa:	6a3b      	ldr	r3, [r7, #32]
 8001aac:	3301      	adds	r3, #1
 8001aae:	623b      	str	r3, [r7, #32]
      pDest++;
 8001ab0:	6a7b      	ldr	r3, [r7, #36]	; 0x24
 8001ab2:	3301      	adds	r3, #1
 8001ab4:	627b      	str	r3, [r7, #36]	; 0x24
      remaining_bytes--;
 8001ab6:	8bfb      	ldrh	r3, [r7, #30]
 8001ab8:	3b01      	subs	r3, #1
 8001aba:	83fb      	strh	r3, [r7, #30]
    } while (remaining_bytes != 0U);
 8001abc:	8bfb      	ldrh	r3, [r7, #30]
 8001abe:	2b00      	cmp	r3, #0
 8001ac0:	d1ea      	bne.n	8001a98 <USB_ReadPacket+0x78>
  }

  return ((void *)pDest);
 8001ac2:	6a7b      	ldr	r3, [r7, #36]	; 0x24
}
 8001ac4:	4618      	mov	r0, r3
 8001ac6:	372c      	adds	r7, #44	; 0x2c
 8001ac8:	46bd      	mov	sp, r7
 8001aca:	f85d 7b04 	ldr.w	r7, [sp], #4
 8001ace:	4770      	bx	lr

08001ad0 <USB_ReadInterrupts>:
  * @brief  USB_ReadInterrupts: return the global USB interrupt status
  * @param  USBx  Selected device
  * @retval HAL status
  */
uint32_t  USB_ReadInterrupts(USB_OTG_GlobalTypeDef *USBx)
{
 8001ad0:	b480      	push	{r7}
 8001ad2:	b085      	sub	sp, #20
 8001ad4:	af00      	add	r7, sp, #0
 8001ad6:	6078      	str	r0, [r7, #4]
  uint32_t tmpreg;

  tmpreg = USBx->GINTSTS;
 8001ad8:	687b      	ldr	r3, [r7, #4]
 8001ada:	695b      	ldr	r3, [r3, #20]
 8001adc:	60fb      	str	r3, [r7, #12]
  tmpreg &= USBx->GINTMSK;
 8001ade:	687b      	ldr	r3, [r7, #4]
 8001ae0:	699b      	ldr	r3, [r3, #24]
 8001ae2:	68fa      	ldr	r2, [r7, #12]
 8001ae4:	4013      	ands	r3, r2
 8001ae6:	60fb      	str	r3, [r7, #12]

  return tmpreg;
 8001ae8:	68fb      	ldr	r3, [r7, #12]
}
 8001aea:	4618      	mov	r0, r3
 8001aec:	3714      	adds	r7, #20
 8001aee:	46bd      	mov	sp, r7
 8001af0:	f85d 7b04 	ldr.w	r7, [sp], #4
 8001af4:	4770      	bx	lr

08001af6 <USB_GetMode>:
  *          This parameter can be one of these values:
  *           0 : Host
  *           1 : Device
  */
uint32_t USB_GetMode(USB_OTG_GlobalTypeDef *USBx)
{
 8001af6:	b480      	push	{r7}
 8001af8:	b083      	sub	sp, #12
 8001afa:	af00      	add	r7, sp, #0
 8001afc:	6078      	str	r0, [r7, #4]
  return ((USBx->GINTSTS) & 0x1U);
 8001afe:	687b      	ldr	r3, [r7, #4]
 8001b00:	695b      	ldr	r3, [r3, #20]
 8001b02:	f003 0301 	and.w	r3, r3, #1
}
 8001b06:	4618      	mov	r0, r3
 8001b08:	370c      	adds	r7, #12
 8001b0a:	46bd      	mov	sp, r7
 8001b0c:	f85d 7b04 	ldr.w	r7, [sp], #4
 8001b10:	4770      	bx	lr

08001b12 <USB_InitFSLSPClkSel>:
  *           HCFG_48_MHZ : Full Speed 48 MHz Clock
  *           HCFG_6_MHZ : Low Speed 6 MHz Clock
  * @retval HAL status
  */
HAL_StatusTypeDef USB_InitFSLSPClkSel(USB_OTG_GlobalTypeDef *USBx, uint8_t freq)
{
 8001b12:	b480      	push	{r7}
 8001b14:	b085      	sub	sp, #20
 8001b16:	af00      	add	r7, sp, #0
 8001b18:	6078      	str	r0, [r7, #4]
 8001b1a:	460b      	mov	r3, r1
 8001b1c:	70fb      	strb	r3, [r7, #3]
  uint32_t USBx_BASE = (uint32_t)USBx;
 8001b1e:	687b      	ldr	r3, [r7, #4]
 8001b20:	60fb      	str	r3, [r7, #12]

  USBx_HOST->HCFG &= ~(USB_OTG_HCFG_FSLSPCS);
 8001b22:	68fb      	ldr	r3, [r7, #12]
 8001b24:	f503 6380 	add.w	r3, r3, #1024	; 0x400
 8001b28:	681b      	ldr	r3, [r3, #0]
 8001b2a:	68fa      	ldr	r2, [r7, #12]
 8001b2c:	f502 6280 	add.w	r2, r2, #1024	; 0x400
 8001b30:	f023 0303 	bic.w	r3, r3, #3
 8001b34:	6013      	str	r3, [r2, #0]
  USBx_HOST->HCFG |= (uint32_t)freq & USB_OTG_HCFG_FSLSPCS;
 8001b36:	68fb      	ldr	r3, [r7, #12]
 8001b38:	f503 6380 	add.w	r3, r3, #1024	; 0x400
 8001b3c:	681a      	ldr	r2, [r3, #0]
 8001b3e:	78fb      	ldrb	r3, [r7, #3]
 8001b40:	f003 0303 	and.w	r3, r3, #3
 8001b44:	68f9      	ldr	r1, [r7, #12]
 8001b46:	f501 6180 	add.w	r1, r1, #1024	; 0x400
 8001b4a:	4313      	orrs	r3, r2
 8001b4c:	600b      	str	r3, [r1, #0]

  if (freq == HCFG_48_MHZ)
 8001b4e:	78fb      	ldrb	r3, [r7, #3]
 8001b50:	2b01      	cmp	r3, #1
 8001b52:	d107      	bne.n	8001b64 <USB_InitFSLSPClkSel+0x52>
  {
    USBx_HOST->HFIR = 48000U;
 8001b54:	68fb      	ldr	r3, [r7, #12]
 8001b56:	f503 6380 	add.w	r3, r3, #1024	; 0x400
 8001b5a:	461a      	mov	r2, r3
 8001b5c:	f64b 3380 	movw	r3, #48000	; 0xbb80
 8001b60:	6053      	str	r3, [r2, #4]
 8001b62:	e009      	b.n	8001b78 <USB_InitFSLSPClkSel+0x66>
  }
  else if (freq == HCFG_6_MHZ)
 8001b64:	78fb      	ldrb	r3, [r7, #3]
 8001b66:	2b02      	cmp	r3, #2
 8001b68:	d106      	bne.n	8001b78 <USB_InitFSLSPClkSel+0x66>
  {
    USBx_HOST->HFIR = 6000U;
 8001b6a:	68fb      	ldr	r3, [r7, #12]
 8001b6c:	f503 6380 	add.w	r3, r3, #1024	; 0x400
 8001b70:	461a      	mov	r2, r3
 8001b72:	f241 7370 	movw	r3, #6000	; 0x1770
 8001b76:	6053      	str	r3, [r2, #4]
  else
  {
    /* ... */
  }

  return HAL_OK;
 8001b78:	2300      	movs	r3, #0
}
 8001b7a:	4618      	mov	r0, r3
 8001b7c:	3714      	adds	r7, #20
 8001b7e:	46bd      	mov	sp, r7
 8001b80:	f85d 7b04 	ldr.w	r7, [sp], #4
 8001b84:	4770      	bx	lr

08001b86 <USB_HC_ReadInterrupt>:
  * @brief Read all host channel interrupts status
  * @param  USBx  Selected device
  * @retval HAL state
  */
uint32_t USB_HC_ReadInterrupt(USB_OTG_GlobalTypeDef *USBx)
{
 8001b86:	b480      	push	{r7}
 8001b88:	b085      	sub	sp, #20
 8001b8a:	af00      	add	r7, sp, #0
 8001b8c:	6078      	str	r0, [r7, #4]
  uint32_t USBx_BASE = (uint32_t)USBx;
 8001b8e:	687b      	ldr	r3, [r7, #4]
 8001b90:	60fb      	str	r3, [r7, #12]

  return ((USBx_HOST->HAINT) & 0xFFFFU);
 8001b92:	68fb      	ldr	r3, [r7, #12]
 8001b94:	f503 6380 	add.w	r3, r3, #1024	; 0x400
 8001b98:	695b      	ldr	r3, [r3, #20]
 8001b9a:	b29b      	uxth	r3, r3
}
 8001b9c:	4618      	mov	r0, r3
 8001b9e:	3714      	adds	r7, #20
 8001ba0:	46bd      	mov	sp, r7
 8001ba2:	f85d 7b04 	ldr.w	r7, [sp], #4
 8001ba6:	4770      	bx	lr

08001ba8 <USB_HC_Halt>:
  * @param  hc_num  Host Channel number
  *         This parameter can be a value from 1 to 15
  * @retval HAL state
  */
HAL_StatusTypeDef USB_HC_Halt(USB_OTG_GlobalTypeDef *USBx, uint8_t hc_num)
{
 8001ba8:	b480      	push	{r7}
 8001baa:	b089      	sub	sp, #36	; 0x24
 8001bac:	af00      	add	r7, sp, #0
 8001bae:	6078      	str	r0, [r7, #4]
 8001bb0:	460b      	mov	r3, r1
 8001bb2:	70fb      	strb	r3, [r7, #3]
  uint32_t USBx_BASE = (uint32_t)USBx;
 8001bb4:	687b      	ldr	r3, [r7, #4]
 8001bb6:	61fb      	str	r3, [r7, #28]
  uint32_t hcnum = (uint32_t)hc_num;
 8001bb8:	78fb      	ldrb	r3, [r7, #3]
 8001bba:	61bb      	str	r3, [r7, #24]
  __IO uint32_t count = 0U;
 8001bbc:	2300      	movs	r3, #0
 8001bbe:	60fb      	str	r3, [r7, #12]
  uint32_t HcEpType = (USBx_HC(hcnum)->HCCHAR & USB_OTG_HCCHAR_EPTYP) >> 18;
 8001bc0:	69bb      	ldr	r3, [r7, #24]
 8001bc2:	015a      	lsls	r2, r3, #5
 8001bc4:	69fb      	ldr	r3, [r7, #28]
 8001bc6:	4413      	add	r3, r2
 8001bc8:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 8001bcc:	681b      	ldr	r3, [r3, #0]
 8001bce:	0c9b      	lsrs	r3, r3, #18
 8001bd0:	f003 0303 	and.w	r3, r3, #3
 8001bd4:	617b      	str	r3, [r7, #20]
  uint32_t ChannelEna = (USBx_HC(hcnum)->HCCHAR & USB_OTG_HCCHAR_CHENA) >> 31;
 8001bd6:	69bb      	ldr	r3, [r7, #24]
 8001bd8:	015a      	lsls	r2, r3, #5
 8001bda:	69fb      	ldr	r3, [r7, #28]
 8001bdc:	4413      	add	r3, r2
 8001bde:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 8001be2:	681b      	ldr	r3, [r3, #0]
 8001be4:	0fdb      	lsrs	r3, r3, #31
 8001be6:	f003 0301 	and.w	r3, r3, #1
 8001bea:	613b      	str	r3, [r7, #16]

  if (((USBx->GAHBCFG & USB_OTG_GAHBCFG_DMAEN) == USB_OTG_GAHBCFG_DMAEN) &&
 8001bec:	687b      	ldr	r3, [r7, #4]
 8001bee:	689b      	ldr	r3, [r3, #8]
 8001bf0:	f003 0320 	and.w	r3, r3, #32
 8001bf4:	2b20      	cmp	r3, #32
 8001bf6:	d104      	bne.n	8001c02 <USB_HC_Halt+0x5a>
 8001bf8:	693b      	ldr	r3, [r7, #16]
 8001bfa:	2b00      	cmp	r3, #0
 8001bfc:	d101      	bne.n	8001c02 <USB_HC_Halt+0x5a>
      (ChannelEna == 0U))
  {
    return HAL_OK;
 8001bfe:	2300      	movs	r3, #0
 8001c00:	e0c8      	b.n	8001d94 <USB_HC_Halt+0x1ec>
  }

  /* Check for space in the request queue to issue the halt. */
  if ((HcEpType == HCCHAR_CTRL) || (HcEpType == HCCHAR_BULK))
 8001c02:	697b      	ldr	r3, [r7, #20]
 8001c04:	2b00      	cmp	r3, #0
 8001c06:	d002      	beq.n	8001c0e <USB_HC_Halt+0x66>
 8001c08:	697b      	ldr	r3, [r7, #20]
 8001c0a:	2b02      	cmp	r3, #2
 8001c0c:	d163      	bne.n	8001cd6 <USB_HC_Halt+0x12e>
  {
    USBx_HC(hcnum)->HCCHAR |= USB_OTG_HCCHAR_CHDIS;
 8001c0e:	69bb      	ldr	r3, [r7, #24]
 8001c10:	015a      	lsls	r2, r3, #5
 8001c12:	69fb      	ldr	r3, [r7, #28]
 8001c14:	4413      	add	r3, r2
 8001c16:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 8001c1a:	681b      	ldr	r3, [r3, #0]
 8001c1c:	69ba      	ldr	r2, [r7, #24]
 8001c1e:	0151      	lsls	r1, r2, #5
 8001c20:	69fa      	ldr	r2, [r7, #28]
 8001c22:	440a      	add	r2, r1
 8001c24:	f502 62a0 	add.w	r2, r2, #1280	; 0x500
 8001c28:	f043 4380 	orr.w	r3, r3, #1073741824	; 0x40000000
 8001c2c:	6013      	str	r3, [r2, #0]

    if ((USBx->GAHBCFG & USB_OTG_GAHBCFG_DMAEN) == 0U)
 8001c2e:	687b      	ldr	r3, [r7, #4]
 8001c30:	689b      	ldr	r3, [r3, #8]
 8001c32:	f003 0320 	and.w	r3, r3, #32
 8001c36:	2b00      	cmp	r3, #0
 8001c38:	f040 80ab 	bne.w	8001d92 <USB_HC_Halt+0x1ea>
    {
      if ((USBx->HNPTXSTS & (0xFFU << 16)) == 0U)
 8001c3c:	687b      	ldr	r3, [r7, #4]
 8001c3e:	6adb      	ldr	r3, [r3, #44]	; 0x2c
 8001c40:	f403 037f 	and.w	r3, r3, #16711680	; 0xff0000
 8001c44:	2b00      	cmp	r3, #0
 8001c46:	d133      	bne.n	8001cb0 <USB_HC_Halt+0x108>
      {
        USBx_HC(hcnum)->HCCHAR &= ~USB_OTG_HCCHAR_CHENA;
 8001c48:	69bb      	ldr	r3, [r7, #24]
 8001c4a:	015a      	lsls	r2, r3, #5
 8001c4c:	69fb      	ldr	r3, [r7, #28]
 8001c4e:	4413      	add	r3, r2
 8001c50:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 8001c54:	681b      	ldr	r3, [r3, #0]
 8001c56:	69ba      	ldr	r2, [r7, #24]
 8001c58:	0151      	lsls	r1, r2, #5
 8001c5a:	69fa      	ldr	r2, [r7, #28]
 8001c5c:	440a      	add	r2, r1
 8001c5e:	f502 62a0 	add.w	r2, r2, #1280	; 0x500
 8001c62:	f023 4300 	bic.w	r3, r3, #2147483648	; 0x80000000
 8001c66:	6013      	str	r3, [r2, #0]
        USBx_HC(hcnum)->HCCHAR |= USB_OTG_HCCHAR_CHENA;
 8001c68:	69bb      	ldr	r3, [r7, #24]
 8001c6a:	015a      	lsls	r2, r3, #5
 8001c6c:	69fb      	ldr	r3, [r7, #28]
 8001c6e:	4413      	add	r3, r2
 8001c70:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 8001c74:	681b      	ldr	r3, [r3, #0]
 8001c76:	69ba      	ldr	r2, [r7, #24]
 8001c78:	0151      	lsls	r1, r2, #5
 8001c7a:	69fa      	ldr	r2, [r7, #28]
 8001c7c:	440a      	add	r2, r1
 8001c7e:	f502 62a0 	add.w	r2, r2, #1280	; 0x500
 8001c82:	f043 4300 	orr.w	r3, r3, #2147483648	; 0x80000000
 8001c86:	6013      	str	r3, [r2, #0]
        do
        {
          count++;
 8001c88:	68fb      	ldr	r3, [r7, #12]
 8001c8a:	3301      	adds	r3, #1
 8001c8c:	60fb      	str	r3, [r7, #12]

          if (count > 1000U)
 8001c8e:	68fb      	ldr	r3, [r7, #12]
 8001c90:	f5b3 7f7a 	cmp.w	r3, #1000	; 0x3e8
 8001c94:	d81d      	bhi.n	8001cd2 <USB_HC_Halt+0x12a>
          {
            break;
          }
        } while ((USBx_HC(hcnum)->HCCHAR & USB_OTG_HCCHAR_CHENA) == USB_OTG_HCCHAR_CHENA);
 8001c96:	69bb      	ldr	r3, [r7, #24]
 8001c98:	015a      	lsls	r2, r3, #5
 8001c9a:	69fb      	ldr	r3, [r7, #28]
 8001c9c:	4413      	add	r3, r2
 8001c9e:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 8001ca2:	681b      	ldr	r3, [r3, #0]
 8001ca4:	f003 4300 	and.w	r3, r3, #2147483648	; 0x80000000
 8001ca8:	f1b3 4f00 	cmp.w	r3, #2147483648	; 0x80000000
 8001cac:	d0ec      	beq.n	8001c88 <USB_HC_Halt+0xe0>
    if ((USBx->GAHBCFG & USB_OTG_GAHBCFG_DMAEN) == 0U)
 8001cae:	e070      	b.n	8001d92 <USB_HC_Halt+0x1ea>
      }
      else
      {
        USBx_HC(hcnum)->HCCHAR |= USB_OTG_HCCHAR_CHENA;
 8001cb0:	69bb      	ldr	r3, [r7, #24]
 8001cb2:	015a      	lsls	r2, r3, #5
 8001cb4:	69fb      	ldr	r3, [r7, #28]
 8001cb6:	4413      	add	r3, r2
 8001cb8:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 8001cbc:	681b      	ldr	r3, [r3, #0]
 8001cbe:	69ba      	ldr	r2, [r7, #24]
 8001cc0:	0151      	lsls	r1, r2, #5
 8001cc2:	69fa      	ldr	r2, [r7, #28]
 8001cc4:	440a      	add	r2, r1
 8001cc6:	f502 62a0 	add.w	r2, r2, #1280	; 0x500
 8001cca:	f043 4300 	orr.w	r3, r3, #2147483648	; 0x80000000
 8001cce:	6013      	str	r3, [r2, #0]
    if ((USBx->GAHBCFG & USB_OTG_GAHBCFG_DMAEN) == 0U)
 8001cd0:	e05f      	b.n	8001d92 <USB_HC_Halt+0x1ea>
            break;
 8001cd2:	bf00      	nop
    if ((USBx->GAHBCFG & USB_OTG_GAHBCFG_DMAEN) == 0U)
 8001cd4:	e05d      	b.n	8001d92 <USB_HC_Halt+0x1ea>
      }
    }
  }
  else
  {
    USBx_HC(hcnum)->HCCHAR |= USB_OTG_HCCHAR_CHDIS;
 8001cd6:	69bb      	ldr	r3, [r7, #24]
 8001cd8:	015a      	lsls	r2, r3, #5
 8001cda:	69fb      	ldr	r3, [r7, #28]
 8001cdc:	4413      	add	r3, r2
 8001cde:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 8001ce2:	681b      	ldr	r3, [r3, #0]
 8001ce4:	69ba      	ldr	r2, [r7, #24]
 8001ce6:	0151      	lsls	r1, r2, #5
 8001ce8:	69fa      	ldr	r2, [r7, #28]
 8001cea:	440a      	add	r2, r1
 8001cec:	f502 62a0 	add.w	r2, r2, #1280	; 0x500
 8001cf0:	f043 4380 	orr.w	r3, r3, #1073741824	; 0x40000000
 8001cf4:	6013      	str	r3, [r2, #0]

    if ((USBx_HOST->HPTXSTS & (0xFFU << 16)) == 0U)
 8001cf6:	69fb      	ldr	r3, [r7, #28]
 8001cf8:	f503 6380 	add.w	r3, r3, #1024	; 0x400
 8001cfc:	691b      	ldr	r3, [r3, #16]
 8001cfe:	f403 037f 	and.w	r3, r3, #16711680	; 0xff0000
 8001d02:	2b00      	cmp	r3, #0
 8001d04:	d133      	bne.n	8001d6e <USB_HC_Halt+0x1c6>
    {
      USBx_HC(hcnum)->HCCHAR &= ~USB_OTG_HCCHAR_CHENA;
 8001d06:	69bb      	ldr	r3, [r7, #24]
 8001d08:	015a      	lsls	r2, r3, #5
 8001d0a:	69fb      	ldr	r3, [r7, #28]
 8001d0c:	4413      	add	r3, r2
 8001d0e:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 8001d12:	681b      	ldr	r3, [r3, #0]
 8001d14:	69ba      	ldr	r2, [r7, #24]
 8001d16:	0151      	lsls	r1, r2, #5
 8001d18:	69fa      	ldr	r2, [r7, #28]
 8001d1a:	440a      	add	r2, r1
 8001d1c:	f502 62a0 	add.w	r2, r2, #1280	; 0x500
 8001d20:	f023 4300 	bic.w	r3, r3, #2147483648	; 0x80000000
 8001d24:	6013      	str	r3, [r2, #0]
      USBx_HC(hcnum)->HCCHAR |= USB_OTG_HCCHAR_CHENA;
 8001d26:	69bb      	ldr	r3, [r7, #24]
 8001d28:	015a      	lsls	r2, r3, #5
 8001d2a:	69fb      	ldr	r3, [r7, #28]
 8001d2c:	4413      	add	r3, r2
 8001d2e:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 8001d32:	681b      	ldr	r3, [r3, #0]
 8001d34:	69ba      	ldr	r2, [r7, #24]
 8001d36:	0151      	lsls	r1, r2, #5
 8001d38:	69fa      	ldr	r2, [r7, #28]
 8001d3a:	440a      	add	r2, r1
 8001d3c:	f502 62a0 	add.w	r2, r2, #1280	; 0x500
 8001d40:	f043 4300 	orr.w	r3, r3, #2147483648	; 0x80000000
 8001d44:	6013      	str	r3, [r2, #0]
      do
      {
        count++;
 8001d46:	68fb      	ldr	r3, [r7, #12]
 8001d48:	3301      	adds	r3, #1
 8001d4a:	60fb      	str	r3, [r7, #12]

        if (count > 1000U)
 8001d4c:	68fb      	ldr	r3, [r7, #12]
 8001d4e:	f5b3 7f7a 	cmp.w	r3, #1000	; 0x3e8
 8001d52:	d81d      	bhi.n	8001d90 <USB_HC_Halt+0x1e8>
        {
          break;
        }
      } while ((USBx_HC(hcnum)->HCCHAR & USB_OTG_HCCHAR_CHENA) == USB_OTG_HCCHAR_CHENA);
 8001d54:	69bb      	ldr	r3, [r7, #24]
 8001d56:	015a      	lsls	r2, r3, #5
 8001d58:	69fb      	ldr	r3, [r7, #28]
 8001d5a:	4413      	add	r3, r2
 8001d5c:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 8001d60:	681b      	ldr	r3, [r3, #0]
 8001d62:	f003 4300 	and.w	r3, r3, #2147483648	; 0x80000000
 8001d66:	f1b3 4f00 	cmp.w	r3, #2147483648	; 0x80000000
 8001d6a:	d0ec      	beq.n	8001d46 <USB_HC_Halt+0x19e>
 8001d6c:	e011      	b.n	8001d92 <USB_HC_Halt+0x1ea>
    }
    else
    {
      USBx_HC(hcnum)->HCCHAR |= USB_OTG_HCCHAR_CHENA;
 8001d6e:	69bb      	ldr	r3, [r7, #24]
 8001d70:	015a      	lsls	r2, r3, #5
 8001d72:	69fb      	ldr	r3, [r7, #28]
 8001d74:	4413      	add	r3, r2
 8001d76:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 8001d7a:	681b      	ldr	r3, [r3, #0]
 8001d7c:	69ba      	ldr	r2, [r7, #24]
 8001d7e:	0151      	lsls	r1, r2, #5
 8001d80:	69fa      	ldr	r2, [r7, #28]
 8001d82:	440a      	add	r2, r1
 8001d84:	f502 62a0 	add.w	r2, r2, #1280	; 0x500
 8001d88:	f043 4300 	orr.w	r3, r3, #2147483648	; 0x80000000
 8001d8c:	6013      	str	r3, [r2, #0]
 8001d8e:	e000      	b.n	8001d92 <USB_HC_Halt+0x1ea>
          break;
 8001d90:	bf00      	nop
    }
  }

  return HAL_OK;
 8001d92:	2300      	movs	r3, #0
}
 8001d94:	4618      	mov	r0, r3
 8001d96:	3724      	adds	r7, #36	; 0x24
 8001d98:	46bd      	mov	sp, r7
 8001d9a:	f85d 7b04 	ldr.w	r7, [sp], #4
 8001d9e:	4770      	bx	lr

08001da0 <USB_StopHost>:
  * @brief  Stop Host Core
  * @param  USBx  Selected device
  * @retval HAL state
  */
HAL_StatusTypeDef USB_StopHost(USB_OTG_GlobalTypeDef *USBx)
{
 8001da0:	b580      	push	{r7, lr}
 8001da2:	b088      	sub	sp, #32
 8001da4:	af00      	add	r7, sp, #0
 8001da6:	6078      	str	r0, [r7, #4]
  HAL_StatusTypeDef ret = HAL_OK;
 8001da8:	2300      	movs	r3, #0
 8001daa:	77fb      	strb	r3, [r7, #31]
  uint32_t USBx_BASE = (uint32_t)USBx;
 8001dac:	687b      	ldr	r3, [r7, #4]
 8001dae:	617b      	str	r3, [r7, #20]
  __IO uint32_t count = 0U;
 8001db0:	2300      	movs	r3, #0
 8001db2:	60fb      	str	r3, [r7, #12]
  uint32_t value;
  uint32_t i;

  (void)USB_DisableGlobalInt(USBx);
 8001db4:	6878      	ldr	r0, [r7, #4]
 8001db6:	f7ff fdbd 	bl	8001934 <USB_DisableGlobalInt>

  /* Flush USB FIFO */
  if (USB_FlushTxFifo(USBx, 0x10U) != HAL_OK) /* all Tx FIFOs */
 8001dba:	2110      	movs	r1, #16
 8001dbc:	6878      	ldr	r0, [r7, #4]
 8001dbe:	f7ff fdcb 	bl	8001958 <USB_FlushTxFifo>
 8001dc2:	4603      	mov	r3, r0
 8001dc4:	2b00      	cmp	r3, #0
 8001dc6:	d001      	beq.n	8001dcc <USB_StopHost+0x2c>
  {
    ret = HAL_ERROR;
 8001dc8:	2301      	movs	r3, #1
 8001dca:	77fb      	strb	r3, [r7, #31]
  }

  if (USB_FlushRxFifo(USBx) != HAL_OK)
 8001dcc:	6878      	ldr	r0, [r7, #4]
 8001dce:	f7ff fdf7 	bl	80019c0 <USB_FlushRxFifo>
 8001dd2:	4603      	mov	r3, r0
 8001dd4:	2b00      	cmp	r3, #0
 8001dd6:	d001      	beq.n	8001ddc <USB_StopHost+0x3c>
  {
    ret = HAL_ERROR;
 8001dd8:	2301      	movs	r3, #1
 8001dda:	77fb      	strb	r3, [r7, #31]
  }

  /* Flush out any leftover queued requests. */
  for (i = 0U; i <= 15U; i++)
 8001ddc:	2300      	movs	r3, #0
 8001dde:	61bb      	str	r3, [r7, #24]
 8001de0:	e01f      	b.n	8001e22 <USB_StopHost+0x82>
  {
    value = USBx_HC(i)->HCCHAR;
 8001de2:	69bb      	ldr	r3, [r7, #24]
 8001de4:	015a      	lsls	r2, r3, #5
 8001de6:	697b      	ldr	r3, [r7, #20]
 8001de8:	4413      	add	r3, r2
 8001dea:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 8001dee:	681b      	ldr	r3, [r3, #0]
 8001df0:	613b      	str	r3, [r7, #16]
    value |=  USB_OTG_HCCHAR_CHDIS;
 8001df2:	693b      	ldr	r3, [r7, #16]
 8001df4:	f043 4380 	orr.w	r3, r3, #1073741824	; 0x40000000
 8001df8:	613b      	str	r3, [r7, #16]
    value &= ~USB_OTG_HCCHAR_CHENA;
 8001dfa:	693b      	ldr	r3, [r7, #16]
 8001dfc:	f023 4300 	bic.w	r3, r3, #2147483648	; 0x80000000
 8001e00:	613b      	str	r3, [r7, #16]
    value &= ~USB_OTG_HCCHAR_EPDIR;
 8001e02:	693b      	ldr	r3, [r7, #16]
 8001e04:	f423 4300 	bic.w	r3, r3, #32768	; 0x8000
 8001e08:	613b      	str	r3, [r7, #16]
    USBx_HC(i)->HCCHAR = value;
 8001e0a:	69bb      	ldr	r3, [r7, #24]
 8001e0c:	015a      	lsls	r2, r3, #5
 8001e0e:	697b      	ldr	r3, [r7, #20]
 8001e10:	4413      	add	r3, r2
 8001e12:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 8001e16:	461a      	mov	r2, r3
 8001e18:	693b      	ldr	r3, [r7, #16]
 8001e1a:	6013      	str	r3, [r2, #0]
  for (i = 0U; i <= 15U; i++)
 8001e1c:	69bb      	ldr	r3, [r7, #24]
 8001e1e:	3301      	adds	r3, #1
 8001e20:	61bb      	str	r3, [r7, #24]
 8001e22:	69bb      	ldr	r3, [r7, #24]
 8001e24:	2b0f      	cmp	r3, #15
 8001e26:	d9dc      	bls.n	8001de2 <USB_StopHost+0x42>
  }

  /* Halt all channels to put them into a known state. */
  for (i = 0U; i <= 15U; i++)
 8001e28:	2300      	movs	r3, #0
 8001e2a:	61bb      	str	r3, [r7, #24]
 8001e2c:	e034      	b.n	8001e98 <USB_StopHost+0xf8>
  {
    value = USBx_HC(i)->HCCHAR;
 8001e2e:	69bb      	ldr	r3, [r7, #24]
 8001e30:	015a      	lsls	r2, r3, #5
 8001e32:	697b      	ldr	r3, [r7, #20]
 8001e34:	4413      	add	r3, r2
 8001e36:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 8001e3a:	681b      	ldr	r3, [r3, #0]
 8001e3c:	613b      	str	r3, [r7, #16]
    value |= USB_OTG_HCCHAR_CHDIS;
 8001e3e:	693b      	ldr	r3, [r7, #16]
 8001e40:	f043 4380 	orr.w	r3, r3, #1073741824	; 0x40000000
 8001e44:	613b      	str	r3, [r7, #16]
    value |= USB_OTG_HCCHAR_CHENA;
 8001e46:	693b      	ldr	r3, [r7, #16]
 8001e48:	f043 4300 	orr.w	r3, r3, #2147483648	; 0x80000000
 8001e4c:	613b      	str	r3, [r7, #16]
    value &= ~USB_OTG_HCCHAR_EPDIR;
 8001e4e:	693b      	ldr	r3, [r7, #16]
 8001e50:	f423 4300 	bic.w	r3, r3, #32768	; 0x8000
 8001e54:	613b      	str	r3, [r7, #16]
    USBx_HC(i)->HCCHAR = value;
 8001e56:	69bb      	ldr	r3, [r7, #24]
 8001e58:	015a      	lsls	r2, r3, #5
 8001e5a:	697b      	ldr	r3, [r7, #20]
 8001e5c:	4413      	add	r3, r2
 8001e5e:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 8001e62:	461a      	mov	r2, r3
 8001e64:	693b      	ldr	r3, [r7, #16]
 8001e66:	6013      	str	r3, [r2, #0]

    do
    {
      count++;
 8001e68:	68fb      	ldr	r3, [r7, #12]
 8001e6a:	3301      	adds	r3, #1
 8001e6c:	60fb      	str	r3, [r7, #12]

      if (count > 1000U)
 8001e6e:	68fb      	ldr	r3, [r7, #12]
 8001e70:	f5b3 7f7a 	cmp.w	r3, #1000	; 0x3e8
 8001e74:	d80c      	bhi.n	8001e90 <USB_StopHost+0xf0>
      {
        break;
      }
    } while ((USBx_HC(i)->HCCHAR & USB_OTG_HCCHAR_CHENA) == USB_OTG_HCCHAR_CHENA);
 8001e76:	69bb      	ldr	r3, [r7, #24]
 8001e78:	015a      	lsls	r2, r3, #5
 8001e7a:	697b      	ldr	r3, [r7, #20]
 8001e7c:	4413      	add	r3, r2
 8001e7e:	f503 63a0 	add.w	r3, r3, #1280	; 0x500
 8001e82:	681b      	ldr	r3, [r3, #0]
 8001e84:	f003 4300 	and.w	r3, r3, #2147483648	; 0x80000000
 8001e88:	f1b3 4f00 	cmp.w	r3, #2147483648	; 0x80000000
 8001e8c:	d0ec      	beq.n	8001e68 <USB_StopHost+0xc8>
 8001e8e:	e000      	b.n	8001e92 <USB_StopHost+0xf2>
        break;
 8001e90:	bf00      	nop
  for (i = 0U; i <= 15U; i++)
 8001e92:	69bb      	ldr	r3, [r7, #24]
 8001e94:	3301      	adds	r3, #1
 8001e96:	61bb      	str	r3, [r7, #24]
 8001e98:	69bb      	ldr	r3, [r7, #24]
 8001e9a:	2b0f      	cmp	r3, #15
 8001e9c:	d9c7      	bls.n	8001e2e <USB_StopHost+0x8e>
  }

  /* Clear any pending Host interrupts */
  USBx_HOST->HAINT = 0xFFFFFFFFU;
 8001e9e:	697b      	ldr	r3, [r7, #20]
 8001ea0:	f503 6380 	add.w	r3, r3, #1024	; 0x400
 8001ea4:	461a      	mov	r2, r3
 8001ea6:	f04f 33ff 	mov.w	r3, #4294967295
 8001eaa:	6153      	str	r3, [r2, #20]
  USBx->GINTSTS = 0xFFFFFFFFU;
 8001eac:	687b      	ldr	r3, [r7, #4]
 8001eae:	f04f 32ff 	mov.w	r2, #4294967295
 8001eb2:	615a      	str	r2, [r3, #20]

  (void)USB_EnableGlobalInt(USBx);
 8001eb4:	6878      	ldr	r0, [r7, #4]
 8001eb6:	f7ff fd2c 	bl	8001912 <USB_EnableGlobalInt>

  return ret;
 8001eba:	7ffb      	ldrb	r3, [r7, #31]
}
 8001ebc:	4618      	mov	r0, r3
 8001ebe:	3720      	adds	r7, #32
 8001ec0:	46bd      	mov	sp, r7
 8001ec2:	bd80      	pop	{r7, pc}

08001ec4 <USBH_LL_IncTimer>:
  *         Increment Host Timer tick
  * @param  phost: Host Handle
  * @retval None
  */
void  USBH_LL_IncTimer(USBH_HandleTypeDef *phost)
{
 8001ec4:	b580      	push	{r7, lr}
 8001ec6:	b082      	sub	sp, #8
 8001ec8:	af00      	add	r7, sp, #0
 8001eca:	6078      	str	r0, [r7, #4]
  phost->Timer++;
 8001ecc:	687b      	ldr	r3, [r7, #4]
 8001ece:	f8d3 33c4 	ldr.w	r3, [r3, #964]	; 0x3c4
 8001ed2:	1c5a      	adds	r2, r3, #1
 8001ed4:	687b      	ldr	r3, [r7, #4]
 8001ed6:	f8c3 23c4 	str.w	r2, [r3, #964]	; 0x3c4
  USBH_HandleSof(phost);
 8001eda:	6878      	ldr	r0, [r7, #4]
 8001edc:	f000 f804 	bl	8001ee8 <USBH_HandleSof>
}
 8001ee0:	bf00      	nop
 8001ee2:	3708      	adds	r7, #8
 8001ee4:	46bd      	mov	sp, r7
 8001ee6:	bd80      	pop	{r7, pc}

08001ee8 <USBH_HandleSof>:
  *         Call SOF process
  * @param  phost: Host Handle
  * @retval None
  */
static void  USBH_HandleSof(USBH_HandleTypeDef *phost)
{
 8001ee8:	b580      	push	{r7, lr}
 8001eea:	b082      	sub	sp, #8
 8001eec:	af00      	add	r7, sp, #0
 8001eee:	6078      	str	r0, [r7, #4]
  if ((phost->gState == HOST_CLASS) && (phost->pActiveClass != NULL))
 8001ef0:	687b      	ldr	r3, [r7, #4]
 8001ef2:	781b      	ldrb	r3, [r3, #0]
 8001ef4:	b2db      	uxtb	r3, r3
 8001ef6:	2b0b      	cmp	r3, #11
 8001ef8:	d10a      	bne.n	8001f10 <USBH_HandleSof+0x28>
 8001efa:	687b      	ldr	r3, [r7, #4]
 8001efc:	f8d3 337c 	ldr.w	r3, [r3, #892]	; 0x37c
 8001f00:	2b00      	cmp	r3, #0
 8001f02:	d005      	beq.n	8001f10 <USBH_HandleSof+0x28>
  {
    phost->pActiveClass->SOFProcess(phost);
 8001f04:	687b      	ldr	r3, [r7, #4]
 8001f06:	f8d3 337c 	ldr.w	r3, [r3, #892]	; 0x37c
 8001f0a:	699b      	ldr	r3, [r3, #24]
 8001f0c:	6878      	ldr	r0, [r7, #4]
 8001f0e:	4798      	blx	r3
  }
}
 8001f10:	bf00      	nop
 8001f12:	3708      	adds	r7, #8
 8001f14:	46bd      	mov	sp, r7
 8001f16:	bd80      	pop	{r7, pc}

08001f18 <USBH_LL_PortEnabled>:
  *         Port Enabled
  * @param  phost: Host Handle
  * @retval None
  */
void USBH_LL_PortEnabled(USBH_HandleTypeDef *phost)
{
 8001f18:	b480      	push	{r7}
 8001f1a:	b083      	sub	sp, #12
 8001f1c:	af00      	add	r7, sp, #0
 8001f1e:	6078      	str	r0, [r7, #4]
  phost->device.PortEnabled = 1U;
 8001f20:	687b      	ldr	r3, [r7, #4]
 8001f22:	2201      	movs	r2, #1
 8001f24:	f883 2323 	strb.w	r2, [r3, #803]	; 0x323
#else
  (void)osMessageQueuePut(phost->os_event, &phost->os_msg, 0U, 0U);
#endif
#endif

  return;
 8001f28:	bf00      	nop
}
 8001f2a:	370c      	adds	r7, #12
 8001f2c:	46bd      	mov	sp, r7
 8001f2e:	f85d 7b04 	ldr.w	r7, [sp], #4
 8001f32:	4770      	bx	lr

08001f34 <USBH_LL_PortDisabled>:
  *         Port Disabled
  * @param  phost: Host Handle
  * @retval None
  */
void USBH_LL_PortDisabled(USBH_HandleTypeDef *phost)
{
 8001f34:	b480      	push	{r7}
 8001f36:	b083      	sub	sp, #12
 8001f38:	af00      	add	r7, sp, #0
 8001f3a:	6078      	str	r0, [r7, #4]
  phost->device.PortEnabled = 0U;
 8001f3c:	687b      	ldr	r3, [r7, #4]
 8001f3e:	2200      	movs	r2, #0
 8001f40:	f883 2323 	strb.w	r2, [r3, #803]	; 0x323

  return;
 8001f44:	bf00      	nop
}
 8001f46:	370c      	adds	r7, #12
 8001f48:	46bd      	mov	sp, r7
 8001f4a:	f85d 7b04 	ldr.w	r7, [sp], #4
 8001f4e:	4770      	bx	lr

08001f50 <USBH_LL_Connect>:
  *         Handle USB Host connexion event
  * @param  phost: Host Handle
  * @retval USBH_Status
  */
USBH_StatusTypeDef  USBH_LL_Connect(USBH_HandleTypeDef *phost)
{
 8001f50:	b480      	push	{r7}
 8001f52:	b083      	sub	sp, #12
 8001f54:	af00      	add	r7, sp, #0
 8001f56:	6078      	str	r0, [r7, #4]
  phost->device.is_connected = 1U;
 8001f58:	687b      	ldr	r3, [r7, #4]
 8001f5a:	2201      	movs	r2, #1
 8001f5c:	f883 2320 	strb.w	r2, [r3, #800]	; 0x320
  phost->device.is_disconnected = 0U;
 8001f60:	687b      	ldr	r3, [r7, #4]
 8001f62:	2200      	movs	r2, #0
 8001f64:	f883 2321 	strb.w	r2, [r3, #801]	; 0x321
  phost->device.is_ReEnumerated = 0U;
 8001f68:	687b      	ldr	r3, [r7, #4]
 8001f6a:	2200      	movs	r2, #0
 8001f6c:	f883 2322 	strb.w	r2, [r3, #802]	; 0x322
#else
  (void)osMessageQueuePut(phost->os_event, &phost->os_msg, 0U, 0U);
#endif
#endif

  return USBH_OK;
 8001f70:	2300      	movs	r3, #0
}
 8001f72:	4618      	mov	r0, r3
 8001f74:	370c      	adds	r7, #12
 8001f76:	46bd      	mov	sp, r7
 8001f78:	f85d 7b04 	ldr.w	r7, [sp], #4
 8001f7c:	4770      	bx	lr

08001f7e <USBH_LL_Disconnect>:
  *         Handle USB Host disconnection event
  * @param  phost: Host Handle
  * @retval USBH_Status
  */
USBH_StatusTypeDef  USBH_LL_Disconnect(USBH_HandleTypeDef *phost)
{
 8001f7e:	b580      	push	{r7, lr}
 8001f80:	b082      	sub	sp, #8
 8001f82:	af00      	add	r7, sp, #0
 8001f84:	6078      	str	r0, [r7, #4]
  /* update device connection states */
  phost->device.is_disconnected = 1U;
 8001f86:	687b      	ldr	r3, [r7, #4]
 8001f88:	2201      	movs	r2, #1
 8001f8a:	f883 2321 	strb.w	r2, [r3, #801]	; 0x321
  phost->device.is_connected = 0U;
 8001f8e:	687b      	ldr	r3, [r7, #4]
 8001f90:	2200      	movs	r2, #0
 8001f92:	f883 2320 	strb.w	r2, [r3, #800]	; 0x320
  phost->device.PortEnabled = 0U;
 8001f96:	687b      	ldr	r3, [r7, #4]
 8001f98:	2200      	movs	r2, #0
 8001f9a:	f883 2323 	strb.w	r2, [r3, #803]	; 0x323

  /* Stop Host */
  (void)USBH_LL_Stop(phost);
 8001f9e:	6878      	ldr	r0, [r7, #4]
 8001fa0:	f000 f883 	bl	80020aa <USBH_LL_Stop>

  /* FRee Control Pipes */
  (void)USBH_FreePipe(phost, phost->Control.pipe_in);
 8001fa4:	687b      	ldr	r3, [r7, #4]
 8001fa6:	791b      	ldrb	r3, [r3, #4]
 8001fa8:	4619      	mov	r1, r3
 8001faa:	6878      	ldr	r0, [r7, #4]
 8001fac:	f000 f80b 	bl	8001fc6 <USBH_FreePipe>
  (void)USBH_FreePipe(phost, phost->Control.pipe_out);
 8001fb0:	687b      	ldr	r3, [r7, #4]
 8001fb2:	795b      	ldrb	r3, [r3, #5]
 8001fb4:	4619      	mov	r1, r3
 8001fb6:	6878      	ldr	r0, [r7, #4]
 8001fb8:	f000 f805 	bl	8001fc6 <USBH_FreePipe>
#else
  (void)osMessageQueuePut(phost->os_event, &phost->os_msg, 0U, 0U);
#endif
#endif

  return USBH_OK;
 8001fbc:	2300      	movs	r3, #0
}
 8001fbe:	4618      	mov	r0, r3
 8001fc0:	3708      	adds	r7, #8
 8001fc2:	46bd      	mov	sp, r7
 8001fc4:	bd80      	pop	{r7, pc}

08001fc6 <USBH_FreePipe>:
  * @param  phost: Host Handle
  * @param  idx: Pipe number to be freed
  * @retval USBH Status
  */
USBH_StatusTypeDef USBH_FreePipe(USBH_HandleTypeDef *phost, uint8_t idx)
{
 8001fc6:	b480      	push	{r7}
 8001fc8:	b083      	sub	sp, #12
 8001fca:	af00      	add	r7, sp, #0
 8001fcc:	6078      	str	r0, [r7, #4]
 8001fce:	460b      	mov	r3, r1
 8001fd0:	70fb      	strb	r3, [r7, #3]
  if (idx < USBH_MAX_PIPES_NBR)
 8001fd2:	78fb      	ldrb	r3, [r7, #3]
 8001fd4:	2b0f      	cmp	r3, #15
 8001fd6:	d80d      	bhi.n	8001ff4 <USBH_FreePipe+0x2e>
  {
    phost->Pipes[idx] &= 0x7FFFU;
 8001fd8:	78fb      	ldrb	r3, [r7, #3]
 8001fda:	687a      	ldr	r2, [r7, #4]
 8001fdc:	33e0      	adds	r3, #224	; 0xe0
 8001fde:	009b      	lsls	r3, r3, #2
 8001fe0:	4413      	add	r3, r2
 8001fe2:	685a      	ldr	r2, [r3, #4]
 8001fe4:	78fb      	ldrb	r3, [r7, #3]
 8001fe6:	f3c2 020e 	ubfx	r2, r2, #0, #15
 8001fea:	6879      	ldr	r1, [r7, #4]
 8001fec:	33e0      	adds	r3, #224	; 0xe0
 8001fee:	009b      	lsls	r3, r3, #2
 8001ff0:	440b      	add	r3, r1
 8001ff2:	605a      	str	r2, [r3, #4]
  }

  return USBH_OK;
 8001ff4:	2300      	movs	r3, #0
}
 8001ff6:	4618      	mov	r0, r3
 8001ff8:	370c      	adds	r7, #12
 8001ffa:	46bd      	mov	sp, r7
 8001ffc:	f85d 7b04 	ldr.w	r7, [sp], #4
 8002000:	4770      	bx	lr

08002002 <HAL_HCD_SOF_Callback>:
  * @brief  SOF callback.
  * @param  hhcd: HCD handle
  * @retval None
  */
void HAL_HCD_SOF_Callback(HCD_HandleTypeDef *hhcd)
{
 8002002:	b580      	push	{r7, lr}
 8002004:	b082      	sub	sp, #8
 8002006:	af00      	add	r7, sp, #0
 8002008:	6078      	str	r0, [r7, #4]
  USBH_LL_IncTimer(hhcd->pData);
 800200a:	687b      	ldr	r3, [r7, #4]
 800200c:	f8d3 3300 	ldr.w	r3, [r3, #768]	; 0x300
 8002010:	4618      	mov	r0, r3
 8002012:	f7ff ff57 	bl	8001ec4 <USBH_LL_IncTimer>
}
 8002016:	bf00      	nop
 8002018:	3708      	adds	r7, #8
 800201a:	46bd      	mov	sp, r7
 800201c:	bd80      	pop	{r7, pc}

0800201e <HAL_HCD_Connect_Callback>:
  * @brief  SOF callback.
  * @param  hhcd: HCD handle
  * @retval None
  */
void HAL_HCD_Connect_Callback(HCD_HandleTypeDef *hhcd)
{
 800201e:	b580      	push	{r7, lr}
 8002020:	b082      	sub	sp, #8
 8002022:	af00      	add	r7, sp, #0
 8002024:	6078      	str	r0, [r7, #4]
  USBH_LL_Connect(hhcd->pData);
 8002026:	687b      	ldr	r3, [r7, #4]
 8002028:	f8d3 3300 	ldr.w	r3, [r3, #768]	; 0x300
 800202c:	4618      	mov	r0, r3
 800202e:	f7ff ff8f 	bl	8001f50 <USBH_LL_Connect>
}
 8002032:	bf00      	nop
 8002034:	3708      	adds	r7, #8
 8002036:	46bd      	mov	sp, r7
 8002038:	bd80      	pop	{r7, pc}

0800203a <HAL_HCD_Disconnect_Callback>:
  * @brief  SOF callback.
  * @param  hhcd: HCD handle
  * @retval None
  */
void HAL_HCD_Disconnect_Callback(HCD_HandleTypeDef *hhcd)
{
 800203a:	b580      	push	{r7, lr}
 800203c:	b082      	sub	sp, #8
 800203e:	af00      	add	r7, sp, #0
 8002040:	6078      	str	r0, [r7, #4]
  USBH_LL_Disconnect(hhcd->pData);
 8002042:	687b      	ldr	r3, [r7, #4]
 8002044:	f8d3 3300 	ldr.w	r3, [r3, #768]	; 0x300
 8002048:	4618      	mov	r0, r3
 800204a:	f7ff ff98 	bl	8001f7e <USBH_LL_Disconnect>
}
 800204e:	bf00      	nop
 8002050:	3708      	adds	r7, #8
 8002052:	46bd      	mov	sp, r7
 8002054:	bd80      	pop	{r7, pc}

08002056 <HAL_HCD_HC_NotifyURBChange_Callback>:
  * @param  chnum: channel number
  * @param  urb_state: state
  * @retval None
  */
void HAL_HCD_HC_NotifyURBChange_Callback(HCD_HandleTypeDef *hhcd, uint8_t chnum, HCD_URBStateTypeDef urb_state)
{
 8002056:	b480      	push	{r7}
 8002058:	b083      	sub	sp, #12
 800205a:	af00      	add	r7, sp, #0
 800205c:	6078      	str	r0, [r7, #4]
 800205e:	460b      	mov	r3, r1
 8002060:	70fb      	strb	r3, [r7, #3]
 8002062:	4613      	mov	r3, r2
 8002064:	70bb      	strb	r3, [r7, #2]
  /* To be used with OS to sync URB state with the global state machine */
#if (USBH_USE_OS == 1)
  USBH_LL_NotifyURBChange(hhcd->pData);
#endif
}
 8002066:	bf00      	nop
 8002068:	370c      	adds	r7, #12
 800206a:	46bd      	mov	sp, r7
 800206c:	f85d 7b04 	ldr.w	r7, [sp], #4
 8002070:	4770      	bx	lr

08002072 <HAL_HCD_PortEnabled_Callback>:
* @brief  Port Port Enabled callback.
  * @param  hhcd: HCD handle
  * @retval None
  */
void HAL_HCD_PortEnabled_Callback(HCD_HandleTypeDef *hhcd)
{
 8002072:	b580      	push	{r7, lr}
 8002074:	b082      	sub	sp, #8
 8002076:	af00      	add	r7, sp, #0
 8002078:	6078      	str	r0, [r7, #4]
  USBH_LL_PortEnabled(hhcd->pData);
 800207a:	687b      	ldr	r3, [r7, #4]
 800207c:	f8d3 3300 	ldr.w	r3, [r3, #768]	; 0x300
 8002080:	4618      	mov	r0, r3
 8002082:	f7ff ff49 	bl	8001f18 <USBH_LL_PortEnabled>
}
 8002086:	bf00      	nop
 8002088:	3708      	adds	r7, #8
 800208a:	46bd      	mov	sp, r7
 800208c:	bd80      	pop	{r7, pc}

0800208e <HAL_HCD_PortDisabled_Callback>:
  * @brief  Port Port Disabled callback.
  * @param  hhcd: HCD handle
  * @retval None
  */
void HAL_HCD_PortDisabled_Callback(HCD_HandleTypeDef *hhcd)
{
 800208e:	b580      	push	{r7, lr}
 8002090:	b082      	sub	sp, #8
 8002092:	af00      	add	r7, sp, #0
 8002094:	6078      	str	r0, [r7, #4]
  USBH_LL_PortDisabled(hhcd->pData);
 8002096:	687b      	ldr	r3, [r7, #4]
 8002098:	f8d3 3300 	ldr.w	r3, [r3, #768]	; 0x300
 800209c:	4618      	mov	r0, r3
 800209e:	f7ff ff49 	bl	8001f34 <USBH_LL_PortDisabled>
}
 80020a2:	bf00      	nop
 80020a4:	3708      	adds	r7, #8
 80020a6:	46bd      	mov	sp, r7
 80020a8:	bd80      	pop	{r7, pc}

080020aa <USBH_LL_Stop>:
  * @brief  Stop the low level portion of the host driver.
  * @param  phost: Host handle
  * @retval USBH status
  */
USBH_StatusTypeDef USBH_LL_Stop(USBH_HandleTypeDef *phost)
{
 80020aa:	b580      	push	{r7, lr}
 80020ac:	b084      	sub	sp, #16
 80020ae:	af00      	add	r7, sp, #0
 80020b0:	6078      	str	r0, [r7, #4]
  HAL_StatusTypeDef hal_status = HAL_OK;
 80020b2:	2300      	movs	r3, #0
 80020b4:	73fb      	strb	r3, [r7, #15]
  USBH_StatusTypeDef usb_status = USBH_OK;
 80020b6:	2300      	movs	r3, #0
 80020b8:	73bb      	strb	r3, [r7, #14]

  hal_status = HAL_HCD_Stop(phost->pData);
 80020ba:	687b      	ldr	r3, [r7, #4]
 80020bc:	f8d3 33d0 	ldr.w	r3, [r3, #976]	; 0x3d0
 80020c0:	4618      	mov	r0, r3
 80020c2:	f7fe fc06 	bl	80008d2 <HAL_HCD_Stop>
 80020c6:	4603      	mov	r3, r0
 80020c8:	73fb      	strb	r3, [r7, #15]

  usb_status = USBH_Get_USB_Status(hal_status);
 80020ca:	7bfb      	ldrb	r3, [r7, #15]
 80020cc:	4618      	mov	r0, r3
 80020ce:	f000 f807 	bl	80020e0 <USBH_Get_USB_Status>
 80020d2:	4603      	mov	r3, r0
 80020d4:	73bb      	strb	r3, [r7, #14]

  return usb_status;
 80020d6:	7bbb      	ldrb	r3, [r7, #14]
}
 80020d8:	4618      	mov	r0, r3
 80020da:	3710      	adds	r7, #16
 80020dc:	46bd      	mov	sp, r7
 80020de:	bd80      	pop	{r7, pc}

080020e0 <USBH_Get_USB_Status>:
  * @brief  Returns the USB status depending on the HAL status:
  * @param  hal_status: HAL status
  * @retval USB status
  */
USBH_StatusTypeDef USBH_Get_USB_Status(HAL_StatusTypeDef hal_status)
{
 80020e0:	b480      	push	{r7}
 80020e2:	b085      	sub	sp, #20
 80020e4:	af00      	add	r7, sp, #0
 80020e6:	4603      	mov	r3, r0
 80020e8:	71fb      	strb	r3, [r7, #7]
  USBH_StatusTypeDef usb_status = USBH_OK;
 80020ea:	2300      	movs	r3, #0
 80020ec:	73fb      	strb	r3, [r7, #15]

  switch (hal_status)
 80020ee:	79fb      	ldrb	r3, [r7, #7]
 80020f0:	2b03      	cmp	r3, #3
 80020f2:	d817      	bhi.n	8002124 <USBH_Get_USB_Status+0x44>
 80020f4:	a201      	add	r2, pc, #4	; (adr r2, 80020fc <USBH_Get_USB_Status+0x1c>)
 80020f6:	f852 f023 	ldr.w	pc, [r2, r3, lsl #2]
 80020fa:	bf00      	nop
 80020fc:	0800210d 	.word	0x0800210d
 8002100:	08002113 	.word	0x08002113
 8002104:	08002119 	.word	0x08002119
 8002108:	0800211f 	.word	0x0800211f
  {
    case HAL_OK :
      usb_status = USBH_OK;
 800210c:	2300      	movs	r3, #0
 800210e:	73fb      	strb	r3, [r7, #15]
    break;
 8002110:	e00b      	b.n	800212a <USBH_Get_USB_Status+0x4a>
    case HAL_ERROR :
      usb_status = USBH_FAIL;
 8002112:	2302      	movs	r3, #2
 8002114:	73fb      	strb	r3, [r7, #15]
    break;
 8002116:	e008      	b.n	800212a <USBH_Get_USB_Status+0x4a>
    case HAL_BUSY :
      usb_status = USBH_BUSY;
 8002118:	2301      	movs	r3, #1
 800211a:	73fb      	strb	r3, [r7, #15]
    break;
 800211c:	e005      	b.n	800212a <USBH_Get_USB_Status+0x4a>
    case HAL_TIMEOUT :
      usb_status = USBH_FAIL;
 800211e:	2302      	movs	r3, #2
 8002120:	73fb      	strb	r3, [r7, #15]
    break;
 8002122:	e002      	b.n	800212a <USBH_Get_USB_Status+0x4a>
    default :
      usb_status = USBH_FAIL;
 8002124:	2302      	movs	r3, #2
 8002126:	73fb      	strb	r3, [r7, #15]
    break;
 8002128:	bf00      	nop
  }
  return usb_status;
 800212a:	7bfb      	ldrb	r3, [r7, #15]
}
 800212c:	4618      	mov	r0, r3
 800212e:	3714      	adds	r7, #20
 8002130:	46bd      	mov	sp, r7
 8002132:	f85d 7b04 	ldr.w	r7, [sp], #4
 8002136:	4770      	bx	lr

08002138 <__libc_init_array>:
 8002138:	b570      	push	{r4, r5, r6, lr}
 800213a:	4d0d      	ldr	r5, [pc, #52]	; (8002170 <__libc_init_array+0x38>)
 800213c:	4c0d      	ldr	r4, [pc, #52]	; (8002174 <__libc_init_array+0x3c>)
 800213e:	1b64      	subs	r4, r4, r5
 8002140:	10a4      	asrs	r4, r4, #2
 8002142:	2600      	movs	r6, #0
 8002144:	42a6      	cmp	r6, r4
 8002146:	d109      	bne.n	800215c <__libc_init_array+0x24>
 8002148:	4d0b      	ldr	r5, [pc, #44]	; (8002178 <__libc_init_array+0x40>)
 800214a:	4c0c      	ldr	r4, [pc, #48]	; (800217c <__libc_init_array+0x44>)
 800214c:	f000 f818 	bl	8002180 <_init>
 8002150:	1b64      	subs	r4, r4, r5
 8002152:	10a4      	asrs	r4, r4, #2
 8002154:	2600      	movs	r6, #0
 8002156:	42a6      	cmp	r6, r4
 8002158:	d105      	bne.n	8002166 <__libc_init_array+0x2e>
 800215a:	bd70      	pop	{r4, r5, r6, pc}
 800215c:	f855 3b04 	ldr.w	r3, [r5], #4
 8002160:	4798      	blx	r3
 8002162:	3601      	adds	r6, #1
 8002164:	e7ee      	b.n	8002144 <__libc_init_array+0xc>
 8002166:	f855 3b04 	ldr.w	r3, [r5], #4
 800216a:	4798      	blx	r3
 800216c:	3601      	adds	r6, #1
 800216e:	e7f2      	b.n	8002156 <__libc_init_array+0x1e>
 8002170:	08002198 	.word	0x08002198
 8002174:	08002198 	.word	0x08002198
 8002178:	08002198 	.word	0x08002198
 800217c:	0800219c 	.word	0x0800219c

08002180 <_init>:
 8002180:	b5f8      	push	{r3, r4, r5, r6, r7, lr}
 8002182:	bf00      	nop
 8002184:	bcf8      	pop	{r3, r4, r5, r6, r7}
 8002186:	bc08      	pop	{r3}
 8002188:	469e      	mov	lr, r3
 800218a:	4770      	bx	lr

0800218c <_fini>:
 800218c:	b5f8      	push	{r3, r4, r5, r6, r7, lr}
 800218e:	bf00      	nop
 8002190:	bcf8      	pop	{r3, r4, r5, r6, r7}
 8002192:	bc08      	pop	{r3}
 8002194:	469e      	mov	lr, r3
 8002196:	4770      	bx	lr