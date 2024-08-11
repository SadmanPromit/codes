document.addEventListener("DOMContentLoaded", function() {
  const sectionId = new URLSearchParams(window.location.search).get("sectionId");

  if (!sectionId) {
    console.error("No sectionId provided in URL");
    return;
  }

  fetch(`/section.php?sectionId=${sectionId}`)
    .then(response => {
      if (!response.ok) throw new Error(response.statusText);
      return response.json();
    })
    .then(data => {
      const sectionDetails = document.querySelector("#section-details");
      sectionDetails.innerHTML = `
        <h1>${data.name}</h1>
        <p>${data.description}</p>
        <!-- Add more fields as necessary -->
      `;
    })
    .catch(error => {
      console.error("Error:", error);
    });
});
