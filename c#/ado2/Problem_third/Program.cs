using Microsoft.EntityFrameworkCore;
using Prob_3.Data;
using Prob_3.Models;

using var db = new AppDbContext();
await db.Database.EnsureCreatedAsync();

if (!await db.Orders.AnyAsync()) {
  var order1 = new Order {
    CustomerName = "Alice",
    TotalAmount = 150.75m,
    OrderDate = DateTime.UtcNow.AddDays(-5),
    Items =
        {
          new OrderItem { ProductName = "Keyboard", Quantity = 1 },
          new OrderItem { ProductName = "Mouse", Quantity = 2 },
        },
  };

  var order2 = new Order {
    CustomerName = "Bob",
    TotalAmount = 320.00m,
    OrderDate = DateTime.UtcNow.AddDays(-2),
    Items =
        {
          new OrderItem { ProductName = "Monitor", Quantity = 1 },
          new OrderItem { ProductName = "Cable", Quantity = 3 },
        },
  };

  db.Orders.AddRange(order1, order2);
  await db.SaveChangesAsync();
}
Console.WriteLine("Введите дату фильтра (например, 2025-10-20):");
var input = Console.ReadLine();
if (DateTime.TryParse(input, out var date)) {
  var results = await db.Orders.Where(o => o.OrderDate > date)
                    .Include(o => o.Items)
                    .Select(o => new {
                      o.Id,
                      o.CustomerName,
                      o.OrderDate,
                      ItemCount = o.Items.Count,
                      SumQuantity = o.Items.Sum(i => i.Quantity),
                      o.TotalAmount,
                    })
                    .ToListAsync();

  Console.WriteLine("\nРезультаты фильтрации:");
  foreach (var r in results) {
    Console.WriteLine($"Заказ {r.Id}: {r.CustomerName} ({r.OrderDate:d})");
    Console.WriteLine(
        $"  Кол-во позиций: {r.ItemCount}, суммарное кол-во: {r.SumQuantity}, сумма: {r.TotalAmount:C}\n");
  }
} else {
  Console.WriteLine("Некорректная дата.");
}
