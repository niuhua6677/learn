package com.hgh.servlet;



import com.hgh.entity.User;
import com.hgh.servise.Loginservise;


import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


import java.io.IOException;


import java.util.List;

@WebServlet("/login")
public class Loginservlet extends HttpServlet {
    private final Loginservise loginservise=new Loginservise();
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws  IOException {
        String username = req.getParameter("username");
        String password = req.getParameter("password");
        List<User> list = loginservise.check(username);
        if(list.isEmpty()){
            resp.setContentType("text/html;charset=utf-8");
            resp.getWriter().write("用户名或密码错误");
        }else{
            if(list.get(0).getPassword().equals(password)){
                resp.setContentType("text/html;charset=utf-8");
                resp.getWriter().write("登陆成功");
            }else{
                resp.setContentType("text/html;charset=utf-8");
                resp.getWriter().write("用户名或密码错误");
            }
        }
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws IOException {
      this.doGet(req,resp);
    }
}
