**UniBedrooms** is a university accommodation management system developed as part of the "Algoritmos e Estruturas de Dados" (AED 22/23) course. The project allows efficient handling of students, managers, rooms, and applications for student housing.

The system is structured around a modular set of Abstract Data Types (ADTs), each responsible for a specific concept such as students, rooms, locations, and managers. Designed with scalability and clarity in mind, it provides a clean separation of concerns between components and utilizes efficient data structures such as open-addressing hash tables and sequences.

---

##  Project Overview

The `uniBedrooms` system was developed in two phases:

- **Phase 1:** Core ADT implementations and basic functionality.
- **Phase 2:** Performance optimizations and additional features like open-addressing hash tables and lexicographic sorting.

### Key Capabilities

- Registering students and managers.
- Managing room listings.
- Submitting and accepting room applications.
- Tracking and updating a Top 3 list of managers based on rentals.

---

##  Architecture

### 🔹 `uniBedrooms` (Main ADT)

The core system wrapper that contains:
- Dictionaries for `students`, `managers`, `rooms`, and `locations`.
- An array for the **Top 3 Managers** based on rooms rented.

### 🔹 `student` (TAD estudante)

Represents a student:
- Fields: `login`, `name`, `university`, `location`, `age`
- Maintains a sequence of applied room codes.

### 🔹 `manager` (TAD gerente)

Represents a room manager:
- Fields: `login`, `name`, `university`
- Tracks the number of rooms rented.

### 🔹 `room` (TAD quarto)

Represents a university residence room:
- Fields: `code`, `residence name`, `location`, `university`, `description`, `manager login`, `occupancy`, `floor`
- Holds a sequence of student candidacies.

### 🔹 `location` (TAD localidade)

Groups rooms by location:
- Fields: `location name`, `dictionary of rooms`
- Enables efficient room listings per area.

---

##  Features Implemented

-  Insert students (`IE` command)
-  Accept room applications (`AC` command)
-  List rooms grouped by location and sorted lexicographically (`LQ` command)
-  Efficient lookups using **Open Address Hash Tables**
-  Lexicographic sorting with **Quicksort**
-  Maintenance of a **Top 3 Managers** leaderboard
-  Internal collections using **Sequences and Dictionaries**
-  Encapsulated logic outside of `main` using `uniBedrooms` as a control layer

---

> Developed with care and attention to design, this project demonstrates effective use of modularity, abstraction, and algorithmic design in C.
