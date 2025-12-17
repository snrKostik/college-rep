using System;
using System.Linq;
using Microsoft.EntityFrameworkCore;

namespace MyApp;

public class Program {
  public static string AUTHORNAME = "Артур Конан Дойль";

  public static void Main(string[] args) {
    Console.WriteLine("Начало efcore и чето кще");

    InitializeDatabase();
    LoadAuthorWithBooksEagerly();
  }

  private static void InitializeDatabase() {
    using (var context = new LibraryContext()) {
      context.Database.EnsureCreated();
      if (context.Authors.Any()) {
        Console.WriteLine("Данные уже есть, ниче не буду делать");
        return;
      }

      Console.WriteLine("добавка нового автора с книгами");
      var author = new Author {
        Name = AUTHORNAME,
        Books =
            new List<Book> {
              new Book { Title = "Этюд в багровых тонах" },
              new Book { Title = "Знак четырех" },
              new Book { Title = "Собака Баскервилей" },
            },
      };
      context.Authors.Add(author);
      context.SaveChanges();
      Console.WriteLine(
          $"Успешно добавлен {author.Name} с {author.Books.Count}");
    }
  }

  private static void LoadAuthorWithBooksEagerly() {
    using (var context = new LibraryContext()) {
      Console.WriteLine("\nзагрузка автора с книгами EaGeRlY lOaDiNg");
      var authorWithBooks = context.Authors.Include(a => a.Books)
                                .FirstOrDefault(a => a.Name == AUTHORNAME);

      if (authorWithBooks != null) {
        Console.WriteLine(
            $"\nЗагружен {authorWithBooks.Name} ID: {authorWithBooks.AuthorId}");
        Console.WriteLine(
            "книги (быди загружены ➡️➡️➡️**ОДНИМ**⬅️⬅️⬅️(1) запросом):");

        if (authorWithBooks.Books.Any()) {
          foreach (var book in authorWithBooks.Books) {
            Console.WriteLine($"- {book.Title} book_ID: {book.BookId}");
          }
        } else {
          Console.WriteLine("книги не найдены :(");
        }
      } else {
        Console.WriteLine("автор не найден :[");
      }
    }
  }
}
