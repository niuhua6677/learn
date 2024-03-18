package com.hua;

import java.sql.*;
public class jdbc_statement {
    public static void main(String[] args) throws Exception {
        //1.注册驱动
       Class.forName("com.mysql.cj.jdbc.Driver");
        //2.获取连接
        Connection con=DriverManager.
                getConnection("jdbc:mysql://127.0.0.1:3306/test","root","12345");
        //编写sql语句
        String sql="select * from major where id=?";
        //3.创建statement
        PreparedStatement pre=con.prepareStatement(sql);
        //4.占位符号赋值,发送sql语句,并且获取返回结果
        pre.setObject(1,2);
        ResultSet res=pre.executeQuery();
        //5.进行结果集解析
        while (res.next()){
            int id=res.getInt(1);
            String major=res.getNString("major_name");
            System.out.println("id:"+id+"--major:"+major);
        }
        //6.关闭资源
        res.close();
        pre.close();
        con.close();
    }
}
