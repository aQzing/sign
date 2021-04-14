package com.qzing.sign.controller;

import com.qzing.sign.entity.ResponseMsg;
import com.qzing.sign.service.SignService;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import java.util.Date;

/**
 * @author qzing
 * @ClassName: SignController
 * @projectName: sign
 * @description: TODO
 * @date 2021/3/5 9:52
 */
@Controller
@Slf4j
public class SignController {
    @Autowired
    private SignService signService;
    @RequestMapping("test")
    @ResponseBody
    public String testData(){
        return "ok";
    }
    @RequestMapping("testHtml")
    public String testHtml(){
        return "testHtml";
    }
    @RequestMapping("sign")
    public String sign(){
        return "sign";
    }
    @RequestMapping("addSign")
    @ResponseBody
    public ResponseMsg addSign(String id, String name, String location){
        //http://localhost:9091/addSign?id=1231441&name=%E5%BC%A0%E4%B8%89&location=%E5%8C%97%E4%BA%AC%E4%B8%AD%E5%85%B3%E6%9D%91&time=20211025152411
        Date date = new Date();
        signService.addSign(id,name,location,date);
        ResponseMsg rs = new ResponseMsg(200,"签到成功!");
        return rs;
    }
}
