using Prob_2.Data;
using Prob_2.Models;

using var db = new AppDbContext();

var product = new Product {
  Name = "Laptop",
  Price = 1200.50m,
  // Category = "Electronics",
};
db.Products.Add(product);
db.SaveChanges();

Console.WriteLine("Список продуктов:");
foreach (var p in db.Products) {
  Console.WriteLine($"{p.Id}: {p.Name} — {p.Price}€");
  // Console.WriteLine($"{p.Id}: {p.Name} ({p.Category}) — {p.Price}€");
}
