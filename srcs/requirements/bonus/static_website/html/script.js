document.addEventListener("DOMContentLoaded", () => {
  const textToType =
    "Software Engineering Student @ 1337 Coding School.\nSpecializing in low-level systems programming, C/C++, and containerized networking architecture.";
  const typingElement = document.getElementById("typewriter");
  let index = 0;

  // Create the blinking cursor
  const cursor = document.createElement("span");
  cursor.className = "cursor";

  function typeText() {
    if (index < textToType.length) {
      // Handle line breaks properly
      if (textToType.charAt(index) === "\n") {
        typingElement.innerHTML += "<br>";
      } else {
        typingElement.innerHTML += textToType.charAt(index);
      }
      index++;
      // Re-append the cursor so it stays at the end
      typingElement.appendChild(cursor);

      // Randomize typing speed slightly for realism (30ms - 80ms)
      setTimeout(typeText, Math.random() * 50 + 30);
    }
  }

  // Start typing after a short delay
  setTimeout(typeText, 500);
});
