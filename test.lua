
function encode(source,target)
    print("Get info from C++",source.cmd_tp)
    -- create a class instance
    local a = test.A('moo')
    a:printName()


    -- create a class instance
    local t = test.ThirdFormat()
    t:setpayload("set info to C++")
    t.retVal=5
    t:printpayload();
    print("t.retVal=",t.retVal)
    
    --target=t 不能这样赋值给C++的指针内存

    target.retVal=6
    target.setpayload(target,"set info to C++ 11")
    target:setname("set info to C++ 12")

end



