`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/07/2024 02:35:57 PM
// Design Name: 
// Module Name: and_gate
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module and_gate(
    input [31:0] A,
    input [31:0] B,
    output [31:0] C
    );
    assign C = A & B;
endmodule
