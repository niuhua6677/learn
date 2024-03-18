package utils;

import java.lang.reflect.Field;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public  class basedao {
    //非DQL语句的封装
    public int executeUpdate(String sql,Object... params) throws Exception {//可变参数用于传占位符的数据
        //直接调封装好的方法获取连接
        Connection connection = jdbcUtils.getConnection();
        PreparedStatement preparedStatement=connection.prepareStatement(sql);
        //占位符号赋值
        if(params!=null&&params.length!=0) {
            for (int i = 1; i <= params.length; i++) {
                preparedStatement.setObject(i, params[i - 1]);
            }
        }
        int n=preparedStatement.executeUpdate();
        preparedStatement.close();
        //是否回收连接,要考虑是不是事务
        if(connection.getAutoCommit()){
            //不是事务,正常回收
            jdbcUtils.freeConnection();
        }
        return n;
    }
//DQL语句封装
    //使用List<java实体类> list接查询值
    //1.使用泛型
    //2.使用反射技术属性赋值
    public <T> List<T> executeQuery(Class<T> tClass,String sql,Object... params) throws Exception {
        //直接调封装好的方法获取连接
        Connection connection = jdbcUtils.getConnection();
        PreparedStatement preparedStatement = connection.prepareStatement(sql);
        //占位符号赋值
        if (params != null && params.length != 0) {
            for (int i = 1; i <= params.length; i++) {
                preparedStatement.setObject(i, params[i - 1]);
            }
        }
        ResultSet resultSet = preparedStatement.executeQuery();
        List<T> list = new ArrayList<>();
        //获取列的信息
        ResultSetMetaData metaData = resultSet.getMetaData();
        int columnCount = metaData.getColumnCount();
        while (resultSet.next()) {
            T t = tClass.newInstance();//调用类的无参构造函数实例化对象
            for (int i = 1; i <= columnCount; i++) {
                //对象的属性值
                Object value = resultSet.getObject(i);
                String propertyName = metaData.getColumnName(i);
                //反射,给对象的属性值赋值
                Field field = tClass.getDeclaredField(propertyName);
                field.setAccessible(true);//设置属性,打破私有限制
                field.set(t, value);
            }
            list.add(t);
        }
        //关闭
        resultSet.close();
        preparedStatement.close();
        if(connection.getAutoCommit()){
            //不是事务,正常回收
            jdbcUtils.freeConnection();
        }
        return list;
    }
}
