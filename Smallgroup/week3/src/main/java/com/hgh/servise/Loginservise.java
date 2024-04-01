package com.hgh.servise;

import com.hgh.dao.Basedao;
import com.hgh.entity.User;

import java.util.List;

public class Loginservise {
    private final Basedao basedao=new Basedao();
    public List<User> check(String username){
        String sql="select * from user where username=?;";
        try {
           return basedao.executeQuery(User.class,sql,username);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

}
