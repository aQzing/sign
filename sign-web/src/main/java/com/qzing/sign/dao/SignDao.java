package com.qzing.sign.dao;

import org.springframework.beans.factory.annotation.Autowired;

import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.stereotype.Repository;

import java.util.Date;
import java.util.List;
import java.util.Map;

/**
 * @author qzing
 * @ClassName: singDao
 * @projectName: sign
 * @description: TODO
 * @date 2021/3/5 10:12
 */
@Repository
public class SignDao {
    @Autowired
    private JdbcTemplate jdbcTemplate;
    public void testConnection(){
        List<Map<String, Object>> list = jdbcTemplate.queryForList("select *from dutyinfo limit 1");
        list.forEach(
            user->{
                System.out.println(user.get("name"));
        });

    }
    public void addSign(String id, String name, String location, Date date){
        String sql = "insert into user_sign (id,name,location,time) values(?,?,?,?)";
        int update = jdbcTemplate.update(sql, id, name, location, date);
        System.out.println("插入数据："+update);
    }
}
