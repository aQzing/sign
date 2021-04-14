package com.qzing.sign.service;

import com.qzing.sign.dao.SignDao;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

/**
 * @author qzing
 * @ClassName: SignService
 * @projectName: sign
 * @description: TODO
 * @date 2021/3/6 15:53
 */
@Service
public class SignService {
    @Autowired
    private SignDao signDao;
    public void addSign(String id, String name, String location, Date date){
        //SimpleDateFormat simpleDateFormat = new SimpleDateFormat("yyyyMMddHHmmss");
       // Date dateFormat = null;
//        try {
//            dateFormat = simpleDateFormat.parse(date);
//        } catch (ParseException e) {
//            e.printStackTrace();
//        }
        signDao.addSign(id, name, location, date);
    }

}
