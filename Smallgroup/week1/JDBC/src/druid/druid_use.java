package druid;

import com.alibaba.druid.pool.DruidDataSourceFactory;
import org.junit.Test;

import javax.sql.DataSource;
import java.io.InputStream;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.Properties;

public class druid_use {
    @Test
public void druidtest() throws Exception {
    //1.读取外部配置文件
    Properties properties=new Properties();
    //src下的文件,可以使用类加载器
    InputStream ips = druid_use.class.getClassLoader().getResourceAsStream("druid.properties");
    properties.load(ips);
    //2.使用连接池的工具类的工厂模式,创建连接池
    DataSource dataSource= DruidDataSourceFactory.createDataSource(properties);
    Connection connection=dataSource.getConnection();
        //下面为数据库curd,即(这里只展示上面的连接池操作):
        //编写sql语句
        //3.创建statement
        //4.占位符号赋值,发送sql语句,并且获取返回结果
        //5.进行结果集解析
     //3.回收连接
        connection.close();

}
}
