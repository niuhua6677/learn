package utils;

import com.alibaba.druid.pool.DruidDataSourceFactory;
import druid.druid_use;

import javax.sql.DataSource;
import java.io.IOException;
import java.io.InputStream;
import java.sql.Connection;
import java.sql.SQLException;
import java.util.Properties;

public class jdbcUtils {
    private static DataSource dataSource=null;//连接池对象
    private static ThreadLocal<Connection> tl=new ThreadLocal<>();//本地变量
    //封装
    static {
        Properties properties=new Properties();
        InputStream ips = jdbcUtils.class.getClassLoader().getResourceAsStream("druid.properties");
        try {
            properties.load(ips);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        try {
            dataSource= DruidDataSourceFactory.createDataSource(properties);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
    //对外提供连接方法
    public static Connection getConnection() throws SQLException {
        //查看线程本地变量是否存在
        Connection connection= tl.get();
        if(connection==null){
            //不存在,就获取
            connection= dataSource.getConnection();
            tl.set(connection);
        }
        return connection;
    }
    public static void freeConnection() throws Exception {
        Connection connection= tl.get();
        if(connection!=null){
            tl.remove();//清空线程本地变量
            connection.setAutoCommit(true);//事务状态回归
            connection.close();//回收
        }

    }
}
