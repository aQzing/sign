package com.qzing.sign;

import com.qzing.sign.dao.SignDao;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import java.util.Date;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

@SpringBootTest
class SignApplicationTests {
    @Autowired
    private SignDao signDao;


    @Test
    void contextLoads() {
        signDao.testConnection();
    }
    @Test
    void testAdd(){
        String id="123456";
        String name="张三";
        String location = "中关村";
        Date date = new Date();
        signDao.addSign(id,name,location,date);
    }
@Test
    void  testAA(){
        }

}
