
select * from product_category where type = 1;

select * from user where loginName = "aaa" and password = "123";

insert into user value (null,"aa","ynl","123",1,"123124124124","123@163.com","12877432141",1);

select * from product where name like "%华为%" or description like "%华为%" and price <1000 and price >500 and stock > 0 order by price desc;

select * from product where name like "%华为%" or description like "%华为%" and price <1000 and price >500 and stock > 0 order by price desc limit 0,10;

select id from product where stock < 5;

select userId,sum(cost)总额 from `order` group by userId order by sum(cost) desc limit 1;

select * from `order` order by cost desc limit 1;

select userId,sum(cost)sum from `order` group by userId;

select max(e.sum) from `order` a,(select userId,sum(cost)sum from `order` group by userId) e where a.userId = e.userId;

select productId,sum(quantity)总数 from order_detail group by productId order by 总数 desc limit 3;


select u.id,u.loginName,o.id,o.createTime,o.cost from user u inner join `order` o on u.id = o.userId where u.id = 21;

select a.id,a.loginName,b.serialNumber,d.name,
(select e.name from product_category e where  d.categoryLevel1Id = e.id) 分类1,
(select e.name from product_category e where  d.categoryLevel2Id = e.id) 分类2,
(select e.name from product_category e where  d.categoryLevel3Id = e.id) 分类3
from user a
inner join `order` b on a.id = b.userId 
inner join `order_detail` c on b.id = c.orderId 
inner join product d on d.id = c.productId
where a.id = 21 and b.id = 6;


select a.id,a.loginName,b.serialNumber,d.name,
d.categoryLevel1Id,e1.name,
d.categoryLevel2Id,e2.name, 
d.categoryLevel3Id,e3.name
from user a
inner join `order` b on a.id = b.userId 
inner join `order_detail` c on b.id = c.orderId 
inner join product d on d.id = c.productId
inner join product_category e1 on e1.id = d.categoryLevel1Id
inner join product_category e2 on e2.id = d.categoryLevel2Id
inner join product_category e3 on e3.id = d.categoryLevel3Id
where a.id = 21 and b.id = 6 ;

-- 名称，商品所属的一级分类，二级分类，
-- 用户名，订单id 下单日期，消费的金额

select * from user a left join `order` b on a.id = b.userId where b.id is null;
select * from product a left join order_detail b on a.id = b.productId;
select * from product a left join order_detail b on a.id = b.productId where b.id is not null;
select a.*,sum(b.quantity)出售数量 from product a inner join order_detail b on a.id = b.productId group by a.id;
select * from product a left join order_detail b on a.id = b.productId where b.id is null;

select a.*,sum(b.quantity)出售数量 from product a inner join order_detail b on a.id = b.productId group by a.id;
 
select productId,sum(quantity) sum from order_detail group by productId;

select * from 
(select productId,sum(quantity) sum from order_detail group by productId) a 
inner join product b on a.productId = b.id 
where a.sum = 
(select max(c.sum) from (select sum(quantity) sum from order_detail group by productId) c);


select a.* from product a where a.id = 
(select productId from order_detail group by productId order by sum(quantity) desc limit 1);





