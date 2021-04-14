package com.qzing.sign.entity;

import lombok.Data;

import java.util.Date;

/**
 * @author qzing
 * @ClassName: SignEntity
 * @projectName: sign
 * @description: TODO
 * @date 2021/3/6 15:40
 */
@Data
public class SignEntity {
    private String id;
    private String name;
    private String location;
    private Date time;
}
