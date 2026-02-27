// Last Stop Boutique Sale
// Write a program that calculates a 5-day sale price schedule for multiple items.
//
// Rules and Specifications:
// 1) Use an outer loop to allow the user to enter multiple items. For each item,
//    ask for the Retail Price and the Wholesale Price.
// 2) Use an inner loop to simulate a 5-day sale starting on Monday.
// 3) Each day, the price drops by 10% of the PREVIOUS day's price.
// 4) Wholesale Floor Rule: The sale price cannot drop below the wholesale price.
//    If a 10% drop pushes the price below wholesale, set the price exactly
//    to the wholesale price for that day and all remaining days.
// 5) Calculate and display the number of days the item was strictly higher
//    than the wholesale price.
// 6) Display a daily price schedule for the 5 days.
//
// Example 1:
//
// Computer: Retail price?
// User: 20.00
// Computer: Wholesale price?
// User: 10.00
// Computer:
// Monday: $18.00
// Tuesday: $16.20
// Wednesday: $14.58
// Thursday: $13.12
// Friday: $11.81
// Days above wholesale: 5
//
// Example 2:
//
// Computer: Retail price?
// User: 25.00
// Computer: Wholesale price?
// User: 20.00
// Computer:
// Monday: $22.50
// Tuesday: $20.25
// Wednesday: $20.00 (Hit wholesale floor)
// Thursday: $20.00
// Friday: $20.00
// Days above wholesale: 2
