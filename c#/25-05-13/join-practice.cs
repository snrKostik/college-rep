using static System.Console;
namespace A {
class JP { // J oin P ractice
  record class Client(int cID, string Name);
  record class Order(int oID, int cID, string Product);

  public void Task2() {
    List<Client> clients = new() {
      new(1, "Bob"),
      new(2, "Dylan"),
      new(3, "Tom"),
    };

    List<Order> orders = new() {
      new(1, 1, "Laptop"),
      new(2, 1, "Keyboard"),
      new(3, 2, "Ice Cream"),
      new(4, 3, "Monitor"),
    };

    var Orders =
        from c in clients join o in orders on c.cID equals o.cID select new {
          oID = o.oID, Name = c.Name, Product = o.Product
        };

    foreach (var o in Orders) {
      WriteLine($"order {o.oID}: {o.Name} buyed {o.Product}");
    }
  }
}
}
