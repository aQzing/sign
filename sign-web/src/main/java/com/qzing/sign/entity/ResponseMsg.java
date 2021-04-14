package com.qzing.sign.entity;

import lombok.AllArgsConstructor;
import lombok.Data;

/**
 * @author qzing
 * @ClassName: ResponseMsg
 * @projectName: sign
 * @description: TODO
 * @date 2021/3/6 16:04
 */
@Data
@AllArgsConstructor
public class ResponseMsg {
    private Integer status = 200;
    private Object body;

}
