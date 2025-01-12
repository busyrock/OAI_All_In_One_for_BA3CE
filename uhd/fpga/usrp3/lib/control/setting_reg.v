//
// Copyright 2011-2012 Ettus Research LLC
//


//----------------------------------------------------------------------
//-- A settings register is a peripheral for the settings register bus.
//-- When the settings register sees strobe abd a matching address,
//-- the outputs will be become registered to the given input bus.
//----------------------------------------------------------------------

module setting_reg
  #(parameter my_addr = 0, 
    parameter awidth = 8,
    parameter width = 32,
    parameter at_reset=0)
    (input clk, input rst, input strobe, input wire [awidth-1:0] addr,
     input wire [31:0] in, output reg [width-1:0] out, output reg changed);
   
   always @(posedge clk)
     if(rst)
     begin
		  out <= at_reset;
		  changed <= 1'b0;
     end
     else
       if(strobe & (my_addr==addr))
		 begin
		 //BA3CE
`ifdef TARGET_B210_BA3CE		 
			//dataout_reg <= 32'h80047000; //BA3CE The actual SPI data is shifted to 1 bytes right, and 0x80047000 is actually 0x00800470. 
			if((in & 32'h83FF00FF)==32'h80040000)    
				out <= ((in & 32'hFFFF00FF) | 32'h00000300); //TX port TX1A TX2A & RX port RX1A RX2A
			else
`endif // !`TARGET_B210_BA3CE	
				out <= in[width-1:0];
			changed <= 1'b1;
		 end
       else
			changed <= 1'b0;
   
endmodule // setting_reg
