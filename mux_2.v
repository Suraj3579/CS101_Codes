module mux_2(z, zbar, a, b, sel);
 
    input a, b, sel;
    output z ,zbar;
    wire selbar, z1, z2;
    
    not i1(selbar, sel);
    and a1(z1, b, sel);
    and a2(z2, a, selbar);
    or r(z, z1, z2);
    not i2(zbar, z);

endmodule
