using System;


namespace TestApp
{
    class Program
    {
        static void Main(string[] args)
        {
            // Prompt the user for their name
            Console.Write("Enter your name: ");
            string name = Console.ReadLine();

            // Prompt the user for their age
            Console.Write("Enter your age: ");
            int age;
            while (!int.TryParse(Console.ReadLine(), out age))
            {
                Console.WriteLine("Invalid input. Please enter a valid age.");
                Console.Write("Enter your age: ");
            }

            // Display the message
            Console.WriteLine($"Hello, {name}! You are {age} years old.");
        }
    }
}
