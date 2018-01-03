# region_grow



Instructions For Defining Regions of Tissue Sample

The following instructions describe a method for interactively outlining Regions of Interest (ROIs) using the GIMP software tool for the identification of tumour morphology (area and perimeter) and to enable a textural comparison between tumour and normal tissue.

**1 Contents of disks**

Disk 1:

- .Instructions - readme.doc (this document).
- .GIMP installation files - gtk+-2.6.2-setup.exe, gimp-2.2.4-setup.exe.
- .Image files (.pnm) – 6

Disk 2:

- .Image files (.pnm) – 7

Disk 3:

- .Image files (.pnm) - 6

2 Install GIMP (GNU Image Manipulation Program)

1. Turn on the computer and insert the CD into the CD-ROM drive.
2. Open the folder called GIMP.
3. Click on **gtk+-2.6.2-setup.exe**.  Follow the on-screen instructions to complete the installation.
4. Click on **gimp-2.2.4-setup.exe**.  Again, follow the on-screen instructions to complete the installation.

3 Run GIMP

1. Open the GIMP application.
2. ![Alt text](resources/readme_images/image_for_readme_1.png?raw=true "GIMP's control panel")

**4 Highlighting Tumour Regions**

1.  In GIMP window:  Click File – Open, and navigate to D drive (disk 1).  Open the first image file 13971\_h.pnm.

1. An image of the tissue slide should appear in a separate window (I will refer to this as the Image window).  Maximise it using the maximise box in the top right corner of window.  The computer screen should appear as the following figure (the image may take some time to load):

![Alt text](resources/readme_images/image_for_readme_2.png?raw=true "Title")

1.   Use the + and – keys to get a feel for zooming in and out.  Whilst tracing areas of interest it is useful to zoom in to make the trace more accurate and to make the line more visible.  Note that working with such large files (90MB) can make operations such as zooming in and out cumbersome.
2. In the GIMP window:

Select the _paint hard edged pixels_ tool, which looks like a pencil.  Change the Brush setting to pixel (1×1) by clicking on the brush-stroke icon and scrolling down.  _Use colour from gradient_ should be _un_checked.

1. In the Image window:

1. Select Layer – New Layer – OK.  Ensure that Transparent is ticked.  This overlays a transparent layer on the slide image.

1.
6.
Open the Layers dialogue box by selecting Dialogues – Layers. The following box should appear.

![Alt text](resources/readme_images/image_for_readme_3.png?raw=true "Title")

1. In the Layers window:

Click on New Layer icon to ensure it is highlighted (in blue).

1. In the Image window (best to click on toolbar at bottom of screen to select it):

Trace around the region/s using the mouse.  The zoom +- buttons can be used to zoom in on the region being traced.  The end of the line should join with the beginning of the line to form a closed loop.

1. In the GIMP window:

Select the fill tool (looks like a bucket of paint) and fill in the region/s by clicking inside them.

1. In the Layers window:

Uncheck the eye next to the background icon to make only the overlying layer visible.  The image window should now look something like this, a chequered background with black-filled regions:

![Alt text](resources/readme_images/image_for_readme_4.png?raw=true "Title")

1. In the Image window:

Click Image – Mode – Indexed then tick _black and white(1bit) palette_.  It may take some time to process.

1. Save the new layer as (_image name)_\_ROI.bmp on C:\ drive (put in a new folder called ROI\_images, say).  For example, the file 14793\_h.pnm would become 14793\_h\_ROI.bmp.  Note, the file extension must be changed from .pnm to .bmp (to create a much reduced binary file size).
2.  When prompted by a warning message about non-compatible file formats, click export.
3.  Repeat the above section for each image file.  In all, there are 19 of them on the 3 disks.
4. When finished save contents of ROI\_images to the provided memory stick.

I thank you very much for your time, it is greatly appreciated.

Chris Finch, Grade A Medical Physics Trainee.
