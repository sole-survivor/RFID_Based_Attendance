extern void delay_ms (unsigned int, unsigned int);
extern void delay_sec (unsigned int, unsigned int);

extern void lcd_data (unsigned char);
extern void lcd_cmd (unsigned char);
extern void lcd_init (void);
extern void lcd_string (char*);

extern void uart0_init(void);
extern void uart0_tx (unsigned char);
extern signed char  uart0_rx (void);
extern void uart0_string_rx (char*,int);
extern void rfid_rx (char*,int);
extern void uart0_string_tx (char*);
